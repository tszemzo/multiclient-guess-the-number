#ifndef CLIENT_H
#define CLIENT_H

#include "common_protocol.h"
#include <string>

/* Clase que representa al cliente de nuestro modelo.*/
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

    /* Booleana que sabe si el cliente debe terminar.*/
    bool has_finish(std::string response);

    /* Responde si esta vivo el cliente.*/
    bool is_alive();

    /* Corre al cliente: recibe un input, lo parsea y envia la respuesta */
    /* mediante el protocolo */
    void run();

    /* Corta la ejecucion del cliente .*/
    void stop();

    // Destructor.
    ~Client();
};

#endif
