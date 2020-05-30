#include <iostream>
#include <string>
// #include "common_socket.h"
#include "args_exception.h"
#include "server.h"

#define SUCCESS 0
#define ERROR 1
#define SERVICE 1
#define NUMBERS_FILE 2
#define PARAMS 3

int main(int argc, char* argv[]) {
    try {
        if (argc != PARAMS) {
            throw ArgsException();
        }
        std::cout << "Hello world" << std::endl;
        Server server(argv[SERVICE], argv[NUMBERS_FILE]);
        server.run();
        return SUCCESS;

    } catch (const std::exception(&e)) {
        std::cout << e.what() << std::endl;
        return ERROR;

    } catch (...) {
        std::cout << "Ocurrió un problema" << std::endl;
        return ERROR;
    }
}
