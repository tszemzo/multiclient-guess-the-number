#ifndef NUMBER_COMMAND_H
#define NUMBER_COMMAND_H

#include <iostream>
#include <string>
#include "common_command.h"

/* Clase que representa a un comando de tipo Help
 */
class Number : public Command {
	private:
	public:
		/*Constructor de la clase.*/
		Number() {}

		/*Ejecuta el comando*/
		void execute() override;

		/*Destructor de la clase.*/
		~Number() {}
};

#endif 
