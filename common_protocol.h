#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "common_socket.h"
#include <string>

/* Clase protocolo que define la comunicacion entre el cliente y el server
 * Vamos a utilizar un socket para la comunicacion
 */
class Protocol {
private:
    Socket socket;

    void send_string_size(int size);

    /* Recibe un número a través del socket */
    uint32_t receive_size();

public:
    /* Constructor que se conecta a la ip y servicio indicados */
    Protocol(const char* ip, const char* service);

    explicit Protocol(Socket&& other_socket);
    Protocol(Protocol&& other) noexcept = default;

    /* Recibe una response */
    std::string receive_response();

    /* Recibe un comando */
    char receive_command();

    /* Recibe un numero */
    uint16_t receive_number();

    /* Envia un numero */
    void send_number(int number);

    /* Envia un comando */
    void send_command(char command);

    /* Envía un string */
    void send_string(const std::string& message);

    /* Cierra el socket */
    void shutdown(int mode);

    ~Protocol();
};

#endif // PROTOCOL_H
