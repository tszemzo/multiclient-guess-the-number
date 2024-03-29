#include <iostream>
#include "client.h"
#include "client_input_parser.h"
#include "common_os_error.h"

#define LOST_MESSAGE "Perdiste"
#define WON_MESSAGE "Ganaste"

Client::Client(Protocol* protocol) {
    socket_protocol = protocol;
    alive = true;
}

void Client::run() {
    InputParser input_parser;
    while (alive) {
        try {
            std::string input;
            std::getline(std::cin, input);
            char command = input_parser.parse(input);
            socket_protocol->send_command(command);
            if (input_parser.is_number(input)) {
                int number = std::stoi(input);
                socket_protocol->send_number(number);
            }
            std::string response = socket_protocol->receive_response();
            std::cout << response << std::endl;
            if (has_finish(response)) this->stop();
        } catch (OSError& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
}

bool Client::has_finish(std::string response) {
    return response == "" || 
           response == LOST_MESSAGE || 
           response == WON_MESSAGE;
}

void Client::stop() {
    alive = false;
}

bool Client::is_alive() {
    return alive;
}

Client::~Client() {
}
