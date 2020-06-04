#include <iostream>
#include "common_command_factory.h"

#define HELP_COMMAND 'h'
#define SURRENDER_COMMAND 's'
#define NUMBER_COMMAND 'n'

Command* CommandFactory::make_command(const char command) {
    if (command == HELP_COMMAND) {
        std::cout << "its help command" << std::endl;
        return new Help();
    } else if (command == SURRENDER_COMMAND) {
        std::cout << "its surrender command" << std::endl;
        return new Surrender();
    } else {
        std::cout << "its a number command" << std::endl;
        return new Number();
    }
}
