#ifndef NUMBER_COMMAND_H
#define NUMBER_COMMAND_H

#include <iostream>
#include <string>
#include <map>
#include "common_command.h"
#include "common_protocol.h"
#include "server_score.h"

/* Clase que representa a un comando de tipo Help
 */
class Number : public Command {
	private:
		Protocol *socket_protocol;
		int current_round;
		int current_number;
		Score &score;

		bool any_digit_repeated(int number, int other);
		bool contains_cipher(int number, int cipher);
		std::map<std::string, int> compare_ciphers(int number, int other);
		void print_results(std::map<std::string, int> results);
		
	public:
		/*Constructor de la clase.*/
		Number(Protocol *socket_protocol, int round, int number, Score& score);

		/*Ejecuta el comando*/
		void execute() override;

		/*Ejecuta el comando*/
		void process(uint16_t number);
		
		/*Destructor de la clase.*/
		~Number() {}
};

#endif 
