#ifndef NUMBER_COMMAND_H
#define NUMBER_COMMAND_H

#include <iostream>
#include <string>
#include <map>
#include "common_command.h"
#include "common_protocol.h"
#include "server_score.h"
#include "common_game.h"

/* Clase que representa a un comando de tipo Help
 */
class Number : public Command {
	private:
		Protocol *socket_protocol;
		Game &game;

		void process(uint16_t number);
		void process_invalid();
		bool valid_number(int number);
		bool any_digit_repeated(int number, int other);
		bool contains_cipher(int number, int cipher);
		std::map<std::string, int> compare_ciphers(int number, int other);
		std::string parse_results(std::map<std::string, int> results);
		
	public:
		/*Constructor de la clase.*/
		Number(Protocol *socket_protocol, Game &game);

		/*Ejecuta el comando*/
		void execute() override;

		/*Destructor de la clase.*/
		~Number() {}
};

#endif 
