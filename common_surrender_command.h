#ifndef SURRENDER_COMMAND_H
#define SURRENDER_COMMAND_H

#include <iostream>
#include <string>
#include "common_command.h"

/* Clase que representa a un comando de tipo Help
 */
class Surrender : public Command {
	private:
	public:
		/*Constructor de la clase.*/
		Surrender() {}

		/*Ejecuta el comando*/
		void execute() override;

		/*Destructor de la clase.*/
		~Surrender() {}
};

#endif 
