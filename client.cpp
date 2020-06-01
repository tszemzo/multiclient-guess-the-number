#include <iostream>
#include "client.h"
#include "client_input_parser.h"
#include "common_os_error.h"

Client::Client(Protocol* protocol) {
    protocol = protocol;
    alive = true;
}

void Client::run() {
    InputParser input_parser;
    std::cout << "Client running" << std::endl;
    while (alive) {
        try {
            std::string input;
            std::getline(std::cin, input);
            char command = input_parser.parse(input);
            protocol->send_command(command);
            if (input_parser.is_number(input)) {
                int number = std::stoi(input);
                protocol->send_number(number);
            }
            std::string response = protocol->receive_response();
            if (response == "") this->stop();
            std::cout << "The response was: " << response << std::endl;
        } catch (OSError& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
}

void Client::stop() {
    alive = false;
    protocol->shutdown(SHUT_RDWR);
}

bool Client::is_alive() {
    return alive;
}

Client::~Client() {
}
