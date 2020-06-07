#include <iostream>
#include <utility>
#include "server.h"

#define COMMAND_SIZE 1
#define NUMBER_SIZE 2
#define SURRENDER_MESSAGE "Perdiste"
#define SURRENDER_MESSAGE_SIZE 8
#define HELP_MESSAGE "Comandos válidos: \n\t​ AYUDA: despliega la lista de comandos válidos​ \n\t​ RENDIRSE: pierde el juego automáticamente​ \n\t​ XXX: Número de 3 cifras a ser enviado al servidor para adivinar el número secreto"
#define HELP_MESSAGE_SIZE 216

Server::Server(const char* service, const char* numbers_file) : 
    socket(service), parser(numbers_file) {
    parser.parse_file(numbers);
    socket.listen();
    running = true;
}

void Server::run() {
    Score score;
    while (running) {
        try {
            std::cout << "Estamos corriendo" << std::endl;
            Socket client_socket = socket.accept();
            // TODO: here should go a handler for the numbersfile
            int current_number = numbers[0];
            ClientHandler* client = new ClientHandler(std::move(client_socket),
                clients.size(), current_number, score);
            clients.push_back(client);
            client->run();
            running = false;
            delete client;
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

void Server::print_results(Score &score){
    score.print_score();
}

Server::~Server() {
}
