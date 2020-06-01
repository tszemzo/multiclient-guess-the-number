#ifndef CLIENT_H
#define CLIENT_H

#include "common_protocol.h"
#include <string>

class Client {
private:
    Protocol* protocol;
    bool alive;

    // No copiable.
    Client(const Client &other) = delete;
    Client& operator=(const Client &other) = delete;

public:
    // Constructor.
    Client(Protocol* Protocol);

    void parse_input(std::string input);
    bool is_alive();
    void run();
    void stop();

    // Destructor.
    ~Client();
};

#endif
