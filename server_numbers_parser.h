#ifndef NUMBERS_PARSER_H
#define NUMBERS_PARSER_H

#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include "server_numbers_handler.h"

/*Clase que parsea el archivo de numeros cuando se inicia el servidor.*/
class NumbersParser {
private:
    std::fstream numbers_file;
    const char *filename;

public:
    /*Crea el lector asignandole el archivo abierto 
    (se usa char *file para ello) como atributo.*/
    explicit NumbersParser(const char* filename);

    /*Llena el array con los numeros obtenidos en el archivo.*/
    void parse_file(NumbersHandler &numbers);

    /*Valida un numero leido del archivo lanzando excepcion en caso de error.*/
    void validate_number(std::string number);

    /*Destructor del objeto. Cierra el archivo que tiene como atributo.*/
    ~NumbersParser();
};

#endif // NUMBERS_PARSER_H
