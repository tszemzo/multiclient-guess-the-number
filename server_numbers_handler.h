#ifndef NUMBERS_HANDLER_H
#define NUMBERS_HANDLER_H

#include <mutex>
#include <iostream>
#include <vector>

/*Clase que modela el tanteador del programa.*/
class NumbersHandler {
private:
    unsigned int current_index;
    std::vector<int> numbers;
    std::mutex m;

public:
    /*Constructor del handler.*/
    NumbersHandler();

    /*Devuelve el proximo numero a adivinar*/
    int next_number();

    /*Agrega un numero a la lista*/
    void push_back(int number);

    /*Destructor del objeto.*/
    ~NumbersHandler();
};

#endif // NUMBERS_HANDLER_H
