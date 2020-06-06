#include "common_number_command.h"
#include "server_score.h"
#include <map>
#include <string>

#define ROUNDS 10
#define CIPHERS 3
#define WIN_MESSAGE "Ganaste"
#define WRONG "mal"
#define REGULAR "regular"
#define GOOD "bien"

Number::Number(Protocol *protocol, int round, int number, Score& score) 
    : score(score) {
    // Here I should valid the number
    socket_protocol = protocol;
    current_round = round;
    current_number = number;
}

void Number::execute() {
    std::cout << "Ejecutandome NUMBER" << std::endl;
    uint16_t number = socket_protocol->receive_number();
    process(number);
}

void Number::process(uint16_t number) {
    std::cout << "On the PROCESS im receiving " << number << std::endl;
    if (number == current_number) {
        socket_protocol->send_string(WIN_MESSAGE);
        // score.add_winner();
    }
    else if(!any_digit_repeated(number, current_number)){
        std::string wrong_message = std::to_string(CIPHERS) + " " + WRONG;
        socket_protocol->send_string(wrong_message);
        // round ++;
    }
    else {
        std::map<std::string, int> result = compare_ciphers(number, current_number);
        print_results(result);
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
            printf("Wrong digit\n");
        } else {
            printf("Good digit\n");
        }
    }
    if(wrong_digit == CIPHERS) return false;
    else return true;
}

bool Number::contains_cipher(int number, int cipher) {
    int number_cipher;
    bool contains = false;
    while ((number)) {
        number_cipher = number % 10;
        number  = number / 10;

        if (number_cipher == cipher ) {
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

        if (user_number_digit == guess_number_digit ) {
            result[GOOD]++;
            printf(" %d - %d Same digit\n", user_number_digit, guess_number_digit);
        } else if (contains_cipher(guess_number, user_number_digit)) {
            result[REGULAR]++;
            printf(" %d Regular\n", user_number_digit);
        }
    }
    return result;
}

void Number::print_results(std::map<std::string, int> results) {
    if (results[GOOD] > 0 && results[REGULAR] > 0) {
        std::cout << results[GOOD] << " " << GOOD << ", " << results[REGULAR] << " " << REGULAR << std::endl;
    } else if (results[GOOD] > 0) {
        std::cout << results[GOOD] << " " << GOOD << std::endl;
    } else {
        std::cout << results[REGULAR] << " " << REGULAR << std::endl;
    }
}
