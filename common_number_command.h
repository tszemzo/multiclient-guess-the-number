#ifndef NUMBER_COMMAND_H
#define NUMBER_COMMAND_H

#include <iostream>
#include <string>
#include "common_command.h"
#include "common_protocol.h"

/* Clase que representa a un comando de tipo Help
 */
class Number : public Command {
	private:
		Protocol *socket_protocol;
		int current_round;
		int current_number;
	public:
		/*Constructor de la clase.*/
		Number(Protocol *socket_protocol, int round, int number);

		/*Ejecuta el comando*/
		void execute() override;

		/*Destructor de la clase.*/
		~Number() {}
};

#endif 
