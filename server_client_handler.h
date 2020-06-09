#ifndef CLIENT_HANDLER_H
#define CLIENT_HANDLER_H

#include <string>
#include <vector>
#include "common_socket.h"
#include "common_thread.h"
#include "common_protocol.h"
#include "server_score.h"
#include "common_game.h"

/* Clase que representa a un handler del cliente desde el server */
/* Esta implementacion lo hace a traves de hilos */
class ClientHandler : public Thread {
private:
    size_t id;
    Protocol protocol;
    bool alive;
    int number;
    Score &score;

    // No copiable.
    ClientHandler(const ClientHandler &other) = delete;
    ClientHandler& operator=(const ClientHandler &other) = delete;

public:
    ClientHandler(Socket&& socket, size_t id, int current_number, Score &score);
    ClientHandler(ClientHandler&& other) = default;

    /* Corre al hilo correspondiente */
    void run() override;

    /* Frena al hilo correspondiente */
    void stop();

    /* Indica si la ejecucion esta viva */
    bool is_alive() const;

    /* Envia un mensaje a traves del protocolo*/
    void send_message(std::string message);

    ~ClientHandler() override;
};

#endif
