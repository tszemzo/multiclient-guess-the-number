#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "common_os_error.h"
#include "common_command_factory.h"
#include "server_client_handler.h"

#define LOSE_MESSAGE "Perdiste"

ClientHandler::ClientHandler(Socket&& socket, size_t id, int current_number,
    Score &score) 
    : protocol(std::move(socket)), number(current_number), score(score) {
    alive = false;
    this->id = id;
}

void ClientHandler::run() {
    alive = true;
    Game game(number);
    while (alive && !game.is_finished()) {
        char command = this->protocol.receive_command();
        CommandFactory command_factory;
        Command* current_command = command_factory.make_command(command, 
        &protocol, game);
        current_command->execute();
        std::cout << "Round: " << game.get_round() << std::endl;
        delete current_command;
    }
    if (game.has_winner()){
        score.add_winner();
    } else {
        this->protocol.send_string(LOSE_MESSAGE);
        score.add_loser();
    }
    score.print_score();
}

void ClientHandler::stop(){
    alive = false;
    this->protocol.shutdown(SHUT_RDWR);
}

bool ClientHandler::is_alive() const {
    return alive;
}

void ClientHandler::send_message(std::string message) {
    protocol.send_string(message);
}
