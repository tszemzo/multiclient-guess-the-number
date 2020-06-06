#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "common_help_command.h"
#include "common_number_command.h"
#include "common_surrender_command.h"
#include "common_command.h"
#include "common_protocol.h"
#include "server_score.h"
#include <string>

/* Clase que funciona como factory para los distintos tipos
 * de comando de la aplicacion
 */
class CommandFactory {
public:
    CommandFactory() {}

    /* Recibiendo un comando como char crea el comando correspondiente */
    Command* make_command(const char command, Protocol *protocol, Score &score, int round, int number);

    ~CommandFactory() {}
};

#endif // COMMAND_FACTORY_H
