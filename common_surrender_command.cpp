#include "common_surrender_command.h"

#define SURRENDER_MESSAGE "Perdiste"

Surrender::Surrender(Protocol *protocol, Game &game) : game(game) {
    socket_protocol = protocol;
}

void Surrender::execute() {
    std::cout << "Ejecutandome SURRENDER" << std::endl;
    game.lost();
}
