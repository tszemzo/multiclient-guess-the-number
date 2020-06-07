#include "common_game.h"

#define GAME_ROUNDS 10

Game::Game(int guess_number) {
    number = guess_number;
    round = 0;
    win = false;
    lose = false;
}

void Game::add_round() {
    round++;
}

int Game::guess_number() {
    return number;
}

int Game::get_round() {
    return round;
}

void Game::won() {
    win = true;
}

void Game::lost() {
    lose = true;
}

bool Game::has_loser() {
    return lose;
}

bool Game::has_winner() {
    return win;
}

bool Game::is_finished() {
    if (win || lose || round >= GAME_ROUNDS) return true;
    return false;
}

Game::~Game() {}
