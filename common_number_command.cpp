#include "common_number_command.h"

#define ROUNDS 10

Number::Number(Protocol *protocol, int round, int number) {
    // Here i should valid the number
    socket_protocol = protocol;
    current_round = round;
    current_number = number;
}

void Number::execute() {
    std::cout << "Ejecutandome NUMBER" << std::endl;
    uint16_t number = socket_protocol->receive_number();
    std::cout << "On the command im receiving " << number << std::endl;
}
