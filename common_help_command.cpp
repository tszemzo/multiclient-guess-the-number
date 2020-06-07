#include "common_help_command.h"

#define HELP_MESSAGE "Comandos válidos:\n\t​AYUDA: despliega la lista de comandos válidos​\n\t​RENDIRSE: pierde el juego automáticamente​\n\t​XXX: Número de 3 cifras a ser enviado al servidor para adivinar el número secreto"

Help::Help(Protocol *protocol) {
    socket_protocol = protocol;
}

void Help::execute() {
    socket_protocol->send_string(HELP_MESSAGE);
}
