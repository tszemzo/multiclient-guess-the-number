#ifndef SURRENDER_COMMAND_H
#define SURRENDER_COMMAND_H

#include <iostream>
#include <string>
#include "common_command.h"
#include "common_protocol.h"
#include "common_game.h"

/* Clase que representa a un comando de tipo Help
 */
class Surrender : public Command {
	private:
		Protocol *socket_protocol;
		Game &game;
	public:
		/*Constructor de la clase.*/
		explicit Surrender(Protocol *protocol, Game &game);

		/*Ejecuta el comando*/
		void execute() override;

		/*Destructor de la clase.*/
		~Surrender() {}
};

#endif 
