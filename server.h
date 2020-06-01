#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include "common_socket.h"
#include "server_numbers_parser.h"

class Server {
private:
    Socket socket;
    NumbersParser parser;
    std::vector<int> numbers;
    bool running;

    // No copiable.
    Server(const Server &other) = delete;
    Server& operator=(const Server &other) = delete;

public:
    // Constructor.
    Server(const char* service, const char* numbers_file);

    void run();
    void stop();

    // Destructor.
    ~Server();
};

#endif
