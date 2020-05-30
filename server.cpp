#include <iostream>
#include "server.h"

#define QUEUE_LENGTH 10

// Server::Server(const char* port, const char* numbers_file) : socket(port), {
//   socket.listen(QUEUE_LENGTH);
// }

Server::Server(const char* port, const char* numbers_file) {
    keep_running = true;
}

void Server::run() {
    while (keep_running) {
        try {
            std::cout << "Estamos corriendo" << std::endl;
            keep_running = false;
            // Socket client_socket = socket.accept();
        } catch (std::exception& e) {
            if (!keep_running) {
                return;
            }
        }
    }
}

Server::~Server() {
}
