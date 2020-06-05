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
    winners = 0;
    losers = 0;
}

void Server::run() {
    while (running) {
        try {
            std::cout << "Estamos corriendo" << std::endl;
            Socket client_socket = socket.accept();
            // TODO: here should go a handler for the numbersfile
            int current_number = numbers[0];
            ClientHandler* client = new ClientHandler(std::move(client_socket),
                clients.size(), current_number);
            clients.push_back(client);
            client->run();

            // char message_buffer[COMMAND_SIZE];
            // client_socket.receive(message_buffer, COMMAND_SIZE);
            
            // std::cout << "Recibido: " << message_buffer << std::endl;
            // if (*message_buffer == 's') {
            //     client_socket.send(SURRENDER_MESSAGE, SURRENDER_MESSAGE_SIZE);
            // } else if (*message_buffer == 'h') {
            //     client_socket.send(HELP_MESSAGE, HELP_MESSAGE_SIZE);
            // } else if (*message_buffer == 'n') {
            //     char number_buffer[NUMBER_SIZE];
            //     client_socket.receive(number_buffer, NUMBER_SIZE);
            //     // validate the received
            //     std::cout << "Recibi el nro: " << number_buffer << std::endl;
            //     client_socket.send(SURRENDER_MESSAGE, SURRENDER_MESSAGE_SIZE);
            // }
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

void Server::print_results(){
    std::cout << "Estadísticas:​ \n\t​ Ganadores: " << winners << "\n\tPerdedores: " << losers << std::endl;
}

Server::~Server() {
}
