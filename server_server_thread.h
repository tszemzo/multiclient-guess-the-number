#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include "common_socket.h"
#include "common_thread.h"
#include "server_numbers_parser.h"
#include "server_client_handler.h"
#include "server_score.h"

class ServerThread : public Thread {
private:
    Socket socket;
    NumbersParser parser;
    Score score;
    std::vector<int> numbers;
    std::vector<ClientHandler*> clients;
    bool running;
    
    // No copiable.
    ServerThread(const ServerThread &other) = delete;
    ServerThread& operator=(const ServerThread &other) = delete;

public:
    // Constructor.
    ServerThread(const char* service, const char* numbers_file);

    void run();
    void stop();
    void print_results();

    // Destructor.
    ~ServerThread() override;
};

#endif
