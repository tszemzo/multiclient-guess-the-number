#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include "common_socket.h"
#include "common_thread.h"
#include "server_numbers_parser.h"
#include "server_client_handler.h"
#include "server_score.h"
#include "server_numbers_handler.h"

/* Clase que representa al servidor. */
/* Esta implementacion lo hace a traves de un hilo de ejecucion */
class ServerThread : public Thread {
private:
    Socket socket;
    NumbersParser parser;
    Score score;
    NumbersHandler numbers;
    std::vector<ClientHandler*> clients;
    bool running;
    
    // No copiable.
    ServerThread(const ServerThread &other) = delete;
    ServerThread& operator=(const ServerThread &other) = delete;

public:
    // Constructor.
    ServerThread(const char* service, const char* numbers_file);

    /* Metodo que lanza el hilo de ejecucion */
    void run();

    /* Metodo que frena el hilo de ejecucion */
    void stop();

    /* Imprime los resultados finales de la ejecucion */
    void print_results();

    /* En cada iteracion del server recolecta los clientes muertos*/
    void garbage_collector();

    // Destructor.
    ~ServerThread() override;
};

#endif
