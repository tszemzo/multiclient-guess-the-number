#ifndef SURRENDER_COMMAND_H
#define SURRENDER_COMMAND_H

#include <iostream>
#include <string>
#include "common_command.h"
#include "common_protocol.h"

/* Clase que representa a un comando de tipo Help
 */
class Surrender : public Command {
	private:
		Protocol *socket_protocol;
	public:
		/*Constructor de la clase.*/
		Surrender(Protocol *protocol);

		/*Ejecuta el comando*/
		void execute() override;

		/*Destructor de la clase.*/
		~Surrender() {}
};

#endif 
