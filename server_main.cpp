#include <iostream>
#include <string>
#include "common_os_error.h"
#include "server_server_thread.h"
#include "server_score.h"

#define SUCCESS 0
#define ERROR 1
#define SERVICE 1
#define NUMBERS_FILE 2
#define PARAMS 3
#define ARGS_ERROR_MSG "Error: argumentos invalidos."
#define QUIT_COMMAND 'q'

int main(int argc, char* argv[]) {
    try {
        if (argc != PARAMS) {
            throw OSError(ARGS_ERROR_MSG);
        }
        ServerThread server(argv[SERVICE], argv[NUMBERS_FILE]);
        server.start();
        while (true){
            std::string input;
            std::cin >> input;
            if (input.length() == 1 && input.at(0) == QUIT_COMMAND){
                server.print_results();
                server.stop();
                break;
            }
        }
        server.join();
        return SUCCESS;
    } catch (const std::exception(&e)) {
        std::cout << e.what() << std::endl;
        return ERROR;
    } catch (...) {
        std::cout << "Ocurrió un problema" << std::endl;
        return ERROR;
    }
}
