#include "common_help_command.h"

Help::Help(Protocol *protocol) {
    socket_protocol = protocol;
}

void Help::execute() {
    std::string msg_1 = "Comandos válidos:\n\t​AYUDA: despliega la ";
    std::string msg_2 = "lista de comandos válidos​\n\t​RENDIRSE: ";
    std::string msg_3 = "pierde el juego automáticamente​\n\t​XXX: ";
    std::string msg_4 = "Número de 3 cifras a ser enviado al servidor ";
    std::string msg_5 = "para adivinar el número secreto";
    std::string msg = msg_1 + msg_2 + msg_3 + msg_4 + msg_5;
    socket_protocol->send_string(msg);
}
