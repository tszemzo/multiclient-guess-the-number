#include "common_surrender_command.h"

#define SURRENDER_MESSAGE "Perdiste"

Surrender::Surrender(Protocol *protocol) {
    socket_protocol = protocol;
}

void Surrender::execute() {
    std::cout << "Ejecutandome SURRENDER" << std::endl;
    socket_protocol->send_string(SURRENDER_MESSAGE);
}
