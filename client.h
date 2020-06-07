#ifndef CLIENT_H
#define CLIENT_H

#include "common_protocol.h"
#include <string>

class Client {
private:
    Protocol* socket_protocol;
    bool alive;

    // No copiable.
    Client(const Client &other) = delete;
    Client& operator=(const Client &other) = delete;

public:
    // Constructor.
    explicit Client(Protocol* Protocol);

    bool has_finish(std::string response);
    void parse_input(std::string input);
    bool is_alive();
    void run();
    void stop();

    // Destructor.
    ~Client();
};

#endif
