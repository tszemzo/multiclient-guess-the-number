#include <iostream>
#include <string>
#include "server_numbers_parser.h"
#include "common_os_error.h"

#define FILE_ERROR_MSG "No se pudo abrir el archivo de numeros"
#define OUT_OF_RANGE_ERROR_MSG "Error: archivo con números fuera de rango"
#define REPEATED_CIPHERS_ERROR_MSG "Error: formato de los números inválidos"
#define MAX_NUMBER 999
#define MIN_NUMBER 100

NumbersParser::NumbersParser(const char *filename) {
	numbers_file.open(filename, std::fstream::in);
	if (!numbers_file.is_open()) {
        throw OSError(FILE_ERROR_MSG);
	}
}

void NumbersParser::parse_file(NumbersHandler &numbers){
    std::string line;

    while (!numbers_file.eof()) {
        std::getline(numbers_file, line, '\n');
        if (line.length() <= 0) break;
		validate_number(line);
        int current = std::stoi(line);
        numbers.push_back(current);
    }
}

void NumbersParser::validate_number(std::string number){
	int int_number = std::stoi(number);
	if (int_number < MIN_NUMBER || int_number > MAX_NUMBER) {
		throw OSError(OUT_OF_RANGE_ERROR_MSG);
	}
	if (number[0] == number[1] ||
		number[0] == number[2] ||
		number[1] == number[2]) {
		throw OSError(REPEATED_CIPHERS_ERROR_MSG);
	}
}

NumbersParser::~NumbersParser() {
	if(numbers_file.is_open()) {
		numbers_file.close();
	}
}
