#define _POSIX_C_SOURCE 200112L

#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cerrno>
#include <utility>
#include "common_socket.h"
#include "common_os_error.h"

#define GETADDRINFO_ERROR "Getaddrinfo Error"
#define CREATE_ERROR "Socket create Error"
#define SHUTDOWN_ERROR "Socket shutdown Error"
#define SEND_ERROR "Socket send Error"
#define RECEIVE_ERROR "Socket receive Error"
#define LISTEN_ERROR "Socket listen Error"
#define ACCEPT_ERROR "Socket accept Error"
#define QUEUE_LENGTH 10


Socket::Socket(const char* service){
    initialize_socket(*this, nullptr, service, AI_PASSIVE, bind);
}

Socket::Socket(const char* ip, const char* service){
    initialize_socket(*this, ip, service, 0, connect);
}

Socket::Socket(int fd) : fd(fd) {}

Socket::Socket(Socket &&other) noexcept {
    this->fd = other.fd;
    other.fd = -1;
}

Socket& Socket::operator=(Socket &&other) noexcept {
    if (this == &other){
        return *this;
    }
    this->fd = other.fd;
    other.fd = -1;
    return *this;
}

void Socket::listen(){
    int status = ::listen(this->fd, QUEUE_LENGTH);
    if (status == -1) {
        throw OSError(LISTEN_ERROR);
    }
}

Socket Socket::accept(){
    int new_socket = ::accept(this->fd, nullptr, nullptr);
    if (new_socket == -1){
        throw OSError(ACCEPT_ERROR);
    }
    Socket s(new_socket);
    return std::move(s);
}

int Socket::send(const char* buffer, size_t length){
    size_t bytes_sent = 0;
    std::cout << "Sending " << buffer << std::endl;
    std::cout << "Sending " << length << std::endl;
    while (bytes_sent < length) {
        ssize_t status = ::send(this->fd,
                              &buffer[bytes_sent],
                              length - bytes_sent,
                              MSG_NOSIGNAL);

        if (status < 0) {
            throw OSError(SEND_ERROR);
        } else if (status == 0) {
            break;
        } else {
            bytes_sent += status;
        }
    }
    return bytes_sent;
}

int Socket::receive(char* buffer, size_t length){
    std::cout << "Entro al receiver" << std::endl;
    size_t bytes_received = 0;
    while (bytes_received < length) {
        ssize_t status = recv(this->fd,
                              &buffer[bytes_received],
                              length - bytes_received,
                              0);

        if (status < 0) {
            throw OSError(RECEIVE_ERROR);
        } else if (status == 0){
            break;
        } else {
            bytes_received += status;
        }
    }
    return bytes_received;
}

void Socket::shutdown(int mode){
    if (this->fd > 0){
        int status = ::shutdown(this->fd, mode);
        if (status == -1){
            throw OSError(SHUTDOWN_ERROR);
        }
    }
}

Socket::~Socket(){
    if (this->fd > 0){
        ::close(this->fd);
    }
}

void Socket::initialize_socket(Socket& s, const char* ip,
                               const char* service, int flags,
                               int function(int,
                                            const struct sockaddr*,
                                            socklen_t)){
    struct addrinfo hints;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = flags;

    struct addrinfo* addrinfo;
    int status = getaddrinfo(ip, service, &hints, &addrinfo);
    if (status != 0) {
        throw OSError(GETADDRINFO_ERROR);
    }

    struct addrinfo* remote;
    int socket_fd;
    bool connection_established = false;
    for (remote = addrinfo;
         remote != nullptr && !connection_established;
         remote = remote->ai_next) {
        socket_fd = socket(remote->ai_family,
                           remote->ai_socktype,
                           remote->ai_protocol);
                           
        if (socket_fd == -1) {
            continue;
        } else {
            // Así se puede reutilizar el puerto sin esperar timeout
            int val = 1;
            setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

            status = function(socket_fd,
                              remote->ai_addr,
                              remote->ai_addrlen);
            if (status == -1) {
                ::close(socket_fd);
                continue;
            }

            connection_established = true;
            s.fd = socket_fd;
        }
    }
    freeaddrinfo(addrinfo);
    if (!connection_established){
        throw OSError(CREATE_ERROR);
    }
}
