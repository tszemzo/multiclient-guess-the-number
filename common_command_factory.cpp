#include <iostream>
#include "common_command_factory.h"

#define HELP_COMMAND 'h'
#define SURRENDER_COMMAND 's'
#define NUMBER_COMMAND 'n'

Command* CommandFactory::make_command(const char command, Protocol *protocol,
    Game &game) {
    if (command == HELP_COMMAND) {
        return new Help(protocol);
    } else if (command == SURRENDER_COMMAND) {
        return new Surrender(protocol, game);
    } else {
        return new Number(protocol, game);
    }
}
