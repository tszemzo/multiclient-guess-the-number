#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>

/*Clase que parsea los inputs que ingresa el usuario por stdin.*/
class InputParser {
public:
    /* Constructor.*/
    InputParser();

    /* Booleana que chequea si el string es un numero.*/
    bool is_number(const std::string& s);

    /* Booleana que chequea si el input entra en 2 bytes sin signo.*/
    bool is_valid_number(const std::string& s);

    /* Metodo que parsea el input del usuario al comando a enviar.*/
    char parse(std::string input);

    /*Destructor del objeto.*/
    ~InputParser();
};

#endif // INPUT_PARSER_H
