#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H

#include <iostream>
#include <string>
#include "common_command.h"
#include "common_protocol.h"

/* Clase que representa a un comando de tipo Help
 */
class Help : public Command {
	private:
		Protocol *socket_protocol;
	public:
		/*Constructor de la clase.*/
		explicit Help(Protocol *protocol);

		/*Ejecuta el comando*/
		void execute() override;

		/*Destructor de la clase.*/
		~Help() {}
};

#endif 
