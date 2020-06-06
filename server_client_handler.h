#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H

#include <string>
#include <vector>
#include "common_socket.h"
#include "common_protocol.h"
#include "server_score.h"

class ClientHandler {
private:
    size_t id;
    Protocol protocol;
    bool alive;
    int round;
    int number;
    Score &score;

    // No copiable.
    ClientHandler(const ClientHandler &other) = delete;
    ClientHandler& operator=(const ClientHandler &other) = delete;

public:
    ClientHandler(Socket&& socket, size_t id, int current_number, Score &score);
    ClientHandler(ClientHandler&& other) = default;

    void run();

    void stop();

    /* Indica si ya terminó su ejecución */
    bool is_alive() const;

    void send_message(std::string message);

    ~ClientHandler() = default;
};

#endif
