#include <iostream>
#include <string>
#include <algorithm>
#include "client_input_parser.h"
#include "common_os_error.h"

#define COMMAND_ERROR_MSG "Error: comando inválido. Escriba AYUDA para obtener ayuda"
#define HELP_INPUT "AYUDA"
#define SURRENDER_INPUT "RENDIRSE"
#define HELP_COMMAND 'h'
#define SURRENDER_COMMAND 's'
#define NUMBER_COMMAND 'n'
#define MAX_NUMBER 999
#define MIN_NUMBER 100

InputParser::InputParser() {}

bool InputParser::is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

bool InputParser::is_valid_number(const std::string& input) {
	int int_number = std::stoi(input);
    return int_number >= MIN_NUMBER && int_number <= MAX_NUMBER;
}

char InputParser::parse(std::string input) {
    if (input == HELP_INPUT) return HELP_COMMAND;
    else if (input == SURRENDER_INPUT) return SURRENDER_COMMAND;
    else if (is_number(input) && is_valid_number(input)) return NUMBER_COMMAND;
    else 
        throw OSError(COMMAND_ERROR_MSG);
}

InputParser::~InputParser() {}
