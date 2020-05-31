#include <iostream>
#include "server.h"

Server::Server(const char* service, const char* numbers_file) : socket(service), parser(numbers_file) {
    parser.parse_file(numbers);
    socket.listen();
    running = true;
}

void Server::run() {
    while (running) {
        try {
            std::cout << "Estamos corriendo" << std::endl;
            Socket client = socket.accept();
            std::cout << "Hemos aceptado" << std::endl;
            running = false;
        } catch (std::exception& e) {
            if (!running) {
                return;
            }
        }
    }
}

void Server::stop(){
    running = false;
    socket.shutdown(SHUT_RDWR);
}

Server::~Server() {
}
