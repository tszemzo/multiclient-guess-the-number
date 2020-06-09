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
    /*Constructor del juego. Recibe el numero a adivinar*/
    explicit Game(int guess_number);

    /*Agrega un round al juego */
    void add_round();

    /*Devuelve el numero a adivinar */
    int guess_number();

    /*Devuelve el round actual */
    int get_round();

    /*Setea al jugador como perdedor */
    void lost();

    /*Setea al jugador como ganador */
    void won();

    /*Booleano, devuelve verdadero si el jugador gano */
    bool has_winner();

    /*Booleano, devuelve verdadero si el jugador perdio */
    bool has_loser();

    /*Booleano, devuelve verdadero si el juego termino */
    bool is_finished();

    /*Destructor del objeto.*/
    ~Game();
};

#endif // GAME_H
