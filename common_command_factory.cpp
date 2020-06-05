#include <iostream>
#include "common_command_factory.h"

#define HELP_COMMAND 'h'
#define SURRENDER_COMMAND 's'
#define NUMBER_COMMAND 'n'

Command* CommandFactory::make_command(const char command, Protocol *protocol, int round, int number) {
    if (command == HELP_COMMAND) {
        std::cout << "its help command" << std::endl;
        return new Help(protocol);
    } else if (command == SURRENDER_COMMAND) {
        std::cout << "its surrender command" << std::endl;
        return new Surrender(protocol);
    } else {
        std::cout << "its a number command" << std::endl;
        return new Number(protocol, round, number);
    }
}
