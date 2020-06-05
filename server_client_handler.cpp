#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "server_client_handler.h"
#include "common_os_error.h"
#include "common_command_factory.h"

ClientHandler::ClientHandler(Socket&& socket, size_t id, int current_number) : 
    protocol(std::move(socket)), number(current_number) {
    alive = false;
    round = 0;
    this->id = id;
}

void ClientHandler::run() {
    alive = true;
    while (alive) {
        try {
            char command = this->protocol.receive_command();
            std::cout << "Cliente " << std::to_string(id) 
                << ": " << command << std::endl;
            CommandFactory command_factory;
            Command* current_command = command_factory.make_command(command, &protocol, round, number);
            current_command->execute();
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
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
