#ifndef GAME_H
#define GAME_H

#include "server_score.h"

/*Clase que modela el juego del programa.*/
class Game {
private:
    int number;
    int round;
    bool win;
    bool lose;

public:
    /*Constructor del tanteador.*/
    explicit Game(int guess_number);

    void add_round();

    int guess_number();

    int get_round();

    void lost();

    void won();

    bool has_winner();

    bool has_loser();

    bool is_finished();

    /*Destructor del objeto.*/
    ~Game();
};

#endif // GAME_H
