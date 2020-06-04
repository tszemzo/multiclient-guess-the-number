#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>

/*Clase que parsea los inputs que ingresa el usuario por stdin.*/
class InputParser {
public:
    /* Constructor. */
    InputParser();

    bool is_number(const std::string& s);

    bool is_valid_number(const std::string& s);

    char parse(std::string input);

    /*Destructor del objeto.*/
    ~InputParser();
};

#endif // INPUT_PARSER_H
