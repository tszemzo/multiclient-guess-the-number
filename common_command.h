#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>

/* Clase que funciona como factory para los distintos tipos
 * de comando de la aplicacion
 */
class Command {
public:
    Command() {}

    /* Ejecuta el comando correspondiente */
    virtual void execute() = 0;

    virtual ~Command() {}
};

#endif // COMMAND_FACTORY_H
