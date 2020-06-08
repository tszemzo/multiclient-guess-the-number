#include "common_number_command.h"
#include "server_score.h"
#include <map>
#include <string>
#include <vector>

#define LAST_ROUND 9
#define CIPHERS 3
#define MIN_NUMBER 100
#define MAX_NUMBER 999
#define ERROR_MESSAGE "Número inválido. Debe ser de 3 cifras no repetidas"
#define LOSE_MESSAGE "Perdiste"
#define WIN_MESSAGE "Ganaste"
#define WRONG "mal"
#define REGULAR "regular"
#define GOOD "bien"

Number::Number(Protocol *protocol, Game &game)
    : game(game) {
    socket_protocol = protocol;
}

void Number::execute() {
    uint16_t number = socket_protocol->receive_number();
    if (valid_number(number)) {
        process(number);
    } else {
        process_invalid();
    }
}

void Number::process(uint16_t number) {
    if (number == game.guess_number()) {
        socket_protocol->send_string(WIN_MESSAGE);
        game.won();
    } else if (number != game.guess_number() && game.get_round() == LAST_ROUND){
        game.lost();
    } else if (!any_digit_repeated(number, game.guess_number())){
        std::string wrong_message = std::to_string(CIPHERS) + " " + WRONG;
        socket_protocol->send_string(wrong_message);
        game.add_round();
    } else {
        std::map<std::string, int> result = compare_ciphers(number, 
        game.guess_number());
        std::string results_message = parse_results(result);
        socket_protocol->send_string(results_message);
        game.add_round();
    }
}

void Number::process_invalid() {
    if (game.get_round() == LAST_ROUND) {
        game.lost();
    } else {
        socket_protocol->send_string(ERROR_MESSAGE);
        game.add_round();
    }
}

bool Number::any_digit_repeated(int number, int other) {
    int other_digit;
    int wrong_digit = 0;
    while (other) {
        other_digit = other % 10;
        other = other / 10;
        if (!contains_cipher(number, other_digit)) {
            wrong_digit++;
        }
    }
    if (wrong_digit == CIPHERS) return false;
    return true;
}

bool Number::contains_cipher(int number, int cipher) {
    int number_cipher;
    bool contains = false;
    while (number) {
        number_cipher = number % 10;
        number  = number / 10;

        if (number_cipher == cipher) {
            contains = true;
        }
    }
    return contains;
}

std::map<std::string, int> Number::compare_ciphers(int number, int other) {
    std::map<std::string, int> result;
    result[REGULAR] = 0;
    result[GOOD] = 0;
    int guess_number = other;
    int user_number_digit;
    int guess_number_digit;
    while (number && other) {
        user_number_digit = number % 10;
        number  = number / 10;
        guess_number_digit = other % 10;
        other = other / 10;

        if (user_number_digit == guess_number_digit) {
            result[GOOD]++;
        } else if (contains_cipher(guess_number, user_number_digit)) {
            result[REGULAR]++;
        }
    }
    return result;
}

std::string Number::parse_results(std::map<std::string, int> results) {
    std::string result_message;
    if (results[GOOD] > 0 && results[REGULAR] > 0) {
        result_message = std::to_string(results[GOOD]) + " " + GOOD + ", " +
        std::to_string(results[REGULAR]) + " " + REGULAR;
    } else if (results[GOOD] > 0) {
        // std::cout << results[GOOD] << " " << GOOD << std::endl;
        result_message = std::to_string(results[GOOD]) + " " + GOOD;
    } else {
        // std::cout << results[REGULAR] << " " << REGULAR << std::endl;
        result_message = std::to_string(results[REGULAR]) + " " + 
        REGULAR;
    }
    return result_message;
}

bool Number::valid_number(int number) {
	if (number < MIN_NUMBER || number > MAX_NUMBER) {
		return false;
	}
    std::vector<int> ciphers;

    while (number) {
        ciphers.push_back(number % 10);
        number = number / 10;
    }
	if (ciphers[0] == ciphers[1] ||
		ciphers[0] == ciphers[2] ||
		ciphers[1] == ciphers[2]) {
        return false;
	}
    return true;
}
