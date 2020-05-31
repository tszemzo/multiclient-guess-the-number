#include <iostream>
#include "client.h"

Client::Client(const char* hostname, const char* service) : socket(hostname, service) {
  alive = true;
}

void Client::run() {
    while (alive) {
        try {
            std::cout << "Client running" << std::endl;
        } catch (std::exception& e) {
            if (!alive) {
                return;
            }
        }
    }
}

void Client::send_string(const std::string& message) {
    int size = message.size();
    std::cout << "Te mando " << message.data() << std::endl;
    socket.send(message.data(), size);
}

void Client::stop(){
    alive = false;
    socket.shutdown(SHUT_RDWR);
}

bool Client::is_alive() {
    return alive;
}

Client::~Client() {
}
