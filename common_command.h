#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>

/* Clase que modela la clase Comando del modelo */
class Command {
public:
    Command() {}

    /* Ejecuta el comando correspondiente */
    virtual void execute() = 0;

    virtual ~Command() {}
};

#endif // COMMAND_H
