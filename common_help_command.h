#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H

#include <iostream>
#include <string>
#include "common_command.h"

/* Clase que representa a un comando de tipo Help
 */
class Help : public Command {
	private:
	public:
		/*Constructor de la clase.*/
		Help() {}

		/*Ejecuta el comando*/
		void execute() override;

		/*Destructor de la clase.*/
		~Help() {}
};

#endif 
