#include "server_numbers_handler.h"

NumbersHandler::NumbersHandler() {
    current_index = 0;
}

int NumbersHandler::next_number() {
	std::unique_lock<std::mutex> lk(m);
    int next = numbers[current_index];
    current_index++;
    if (current_index == numbers.size()) current_index = 0;
    return next;
}

void NumbersHandler::push_back(int number) {
    numbers.push_back(number);
}

NumbersHandler::~NumbersHandler() {}
