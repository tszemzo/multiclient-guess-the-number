#ifndef SCORE_H
#define SCORE_H

#include <mutex>
#include <iostream>

/*Clase que modela el tanteador del programa.*/
class Score {
private:
    int winners;
    int losers;
    std::mutex m;

public:
    /*Constructor del tanteador.*/
    Score();

    /*Suma un ganador al tanteador*/
    bool add_winner();

    /*Suma un perderor al tanteador*/
    bool add_loser();

    /*Imprime por pantalla los ganadores y perdedores del tanteador*/
    void print_score();

    /*Destructor del objeto.*/
    ~Score();
};

#endif // SCORE_H
