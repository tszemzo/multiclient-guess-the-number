#ifndef NUMBER_COMMAND_H
#define NUMBER_COMMAND_H

#include <iostream>
#include <string>
#include <map>
#include "common_command.h"
#include "common_protocol.h"
#include "server_score.h"
#include "common_game.h"

/* Clase que representa a un comando de tipo Numero */
class Number : public Command {
	private:
		Protocol *socket_protocol;
		Game &game;

		/* Procesa un numero para saber si un jugador 
		 * gano/perdio/sigue
		 */
		void process(uint16_t number);

		/* Procesa un numero invalido */
		void process_invalid();

		/* Valida que un numero sea correcto: sin cifras repetidas
		 * y que este entre 100 y 999
		 */
		bool valid_number(int number);

		/* Valida que un numero y otro no tengan cifras repetidas */
		bool any_digit_repeated(int number, int other);

		/* Valida que un numero contenga la cifra cipher */
		bool contains_cipher(int number, int cipher);

		/* Compara las cifras entre dos numeros devolviendo un mapa */
		std::map<std::string, int> compare_ciphers(int number, int other);

		/* Parsea los resultados de la ejecucion del comando */
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
