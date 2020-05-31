#ifndef SERVER_H
#define SERVER_H

#include "common_socket.h"
#include <string>

class Server {

private:
    Socket socket;
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
