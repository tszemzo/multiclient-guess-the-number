#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>
#include <climits>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

/* Clase que representa un socket.*/
class Socket {
private:
    int fd;

    explicit Socket(int fd);

    /* Inicializa el socket recibido.
     * Se espera recibir 'bind' o 'connect' en la function
     */
    void initialize_socket(Socket& s, const char* ip,
                           const char* service, int flags,
                           int function(int,
                                        const struct sockaddr*,
                                        socklen_t));

    /* No permitimos la copia */
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;

public:
    Socket(Socket&& other) noexcept;
    Socket& operator=(Socket &&other) noexcept;

    /* Crea un socket y realiza un bind al puerto indicado */
    explicit Socket(const char* service);

    /* Crea un socket y realiza un connect a la ip y puerto indicados */
    Socket(const char* ip, const char* service);

    /* Realiza la operacion de listen del socket. Se establece en 10 el max */
    /* del tamaño de la cola para conexiones en espera */
    void listen();

    /* Bloquea el socket para aceptar nuevos clientes */
    Socket accept();

    /* Envía un buffer de tamaño length */
    int send(const char* buffer, size_t length);

    /* Recibe data escrita en el buffer */
    int receive(char* buffer, size_t length);

    /* Corta la comunicación del socket. */
    void shutdown(int mode);

    /* Destructor. Cierra el socket */
    ~Socket();
};

#endif // SOCKET_H
