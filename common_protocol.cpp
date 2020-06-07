#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include "common_protocol.h"

#define COMMAND_SIZE 1
#define NUMBER_SIZE 2
#define STRING_SIZE 4

Protocol::Protocol(const char *ip, const char *service) :
    socket(ip, service) {}

Protocol::Protocol(Socket &&other_socket) :
    socket(std::move(other_socket)) {}

uint32_t Protocol::receive_size() {
    char size_buffer[STRING_SIZE];
    socket.receive(size_buffer, STRING_SIZE);
    uint32_t size;
    memcpy(&size, size_buffer, STRING_SIZE);
    uint32_t value = ntohl(size);
    return value;
}

std::string Protocol::receive_response(){
    uint32_t size = receive_size();
    char* response = (char*) malloc(size);
    socket.receive(response, size);
    std::string received(response, size);
    free(response);
    return received;
}

char Protocol::receive_command(){
    char command_buffer[COMMAND_SIZE];
    socket.receive(command_buffer, COMMAND_SIZE);
    char command;
    memcpy(&command, command_buffer, COMMAND_SIZE);
    return command;
}

uint16_t Protocol::receive_number(){
    char number_buffer[NUMBER_SIZE];
    socket.receive(number_buffer, NUMBER_SIZE);
    uint16_t number;
    memcpy(&number, number_buffer, NUMBER_SIZE);
    uint16_t value = ntohs(number);
    return value;
}

void Protocol::send_number(int number) {
    // Big endian
    uint16_t big_endian_number = ntohs(number);
    char number_buffer[NUMBER_SIZE];
    memcpy(number_buffer, &big_endian_number, NUMBER_SIZE);
    socket.send(number_buffer, NUMBER_SIZE);
}

void Protocol::send_command(char command) {
    char command_buffer[COMMAND_SIZE];
    memcpy(command_buffer, &command, COMMAND_SIZE);
    socket.send(command_buffer, COMMAND_SIZE);
}

void Protocol::send_string_size(int size) {
    // Big endian
    uint32_t string_length = htonl(size);
    char string_length_buffer[STRING_SIZE];
    memcpy(string_length_buffer, &string_length, STRING_SIZE);
    socket.send(string_length_buffer, STRING_SIZE);
}

void Protocol::send_string(const std::string& buffer) {
    int buffer_size = buffer.size();
    send_string_size(buffer_size);
    socket.send(buffer.data(), buffer.size());
}

void Protocol::shutdown(int mode){
    socket.shutdown(mode);
}

Protocol::~Protocol() {
    socket.shutdown(SHUT_RDWR);
}
