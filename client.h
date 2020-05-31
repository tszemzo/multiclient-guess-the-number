#ifndef CLIENT_H
#define CLIENT_H

#include "common_socket.h"
#include <string>

class Client {

private:
    Socket socket;
    bool alive;

    // No copiable.
    Client(const Client &other) = delete;
    Client& operator=(const Client &other) = delete;

public:
    // Constructor.
    Client(const char* hostname, const char* service);

    void send_string(const std::string& message);

    bool is_alive();

    void run();
    void stop();

    // Destructor.
    ~Client();
};

#endif
