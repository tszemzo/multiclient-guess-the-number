#include <iostream>
#include <utility>
#include "server_server_thread.h"

ServerThread::ServerThread(const char* service, const char* numbers_file) : 
    socket(service), parser(numbers_file) {
    parser.parse_file(numbers);
    socket.listen();
    running = true;
}

void ServerThread::run() {
    while (running) {
        try {
            Socket client_socket = socket.accept();
            int current_number = numbers.next_number();
            ClientHandler* client = new ClientHandler(std::move(client_socket),
                clients.size(), current_number, score);
            clients.push_back(client);
            client->start();
            if(running) garbage_collector();
        } catch (std::exception& e) {
            if (!running) {
                return;
            }
        }
    }
}

void ServerThread::garbage_collector(){
    std::vector<ClientHandler*> tmp;
    std::vector<ClientHandler*>::iterator it = clients.begin();
    for (; it != clients.end(); ++it) {
        if (!((*it)->is_alive())) {
            (*it)->join();
            delete *it;
            continue;
        }
        tmp.push_back(*it);
    }
    clients.swap(tmp);
}

void ServerThread::stop(){
    running = false;
    for (size_t i = 0; i < clients.size(); ++i) {
        clients[i]->stop();
        clients[i]->join();
        delete clients[i];
    }
    clients.clear();
    socket.shutdown(SHUT_RDWR);
}

void ServerThread::print_results(){
    score.print_score();
}

ServerThread::~ServerThread() {
}
