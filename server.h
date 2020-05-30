#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {

private:
    // Socket socket;
    bool keep_running;

    // No copiable.
    Server(const Server &other) = delete;
    Server& operator=(const Server &other) = delete;

public:
    // Constructor.
    Server(const char* port, const char* numbers_file);

    void run();
    void stop();

    // Destructor.
    ~Server();
};

#endif
