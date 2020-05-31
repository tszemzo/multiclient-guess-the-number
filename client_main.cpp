#include <iostream>
#include <string>
#include "common_os_error.h"

#define SUCCESS 0
#define ERROR 1
#define HOSTNAME 1
#define SERVICE 2
#define PARAMS 3
#define ARGS_ERROR_MSG "Error: argumentos invalidos."

int main(int argc, char* argv[]) {
    try {
		if (argc != PARAMS) {
			throw OSError(ARGS_ERROR_MSG);
		}

		std::cout << "Hola cliente" << std::endl;


	} catch (const std::exception(&e)) {
        std::cout << e.what() << std::endl;

    } catch (...) {
        std::cout << "Ocurrió un problema" << std::endl;
    }
	return SUCCESS;
}
