#include "server_score.h"

Score::Score() {
	winners = 0;
    losers = 0;
}

bool Score::add_winner() {
	std::unique_lock<std::mutex> lk(m);
	winners++;
	return true;
}

bool Score::add_loser() {
	std::unique_lock<std::mutex> lk(m);
	losers++;
	return true;
}

void Score::print_score() {
	std::unique_lock<std::mutex> lk(m);
    std::cout << "Estadísticas:​ \n\t​ Ganadores: " << winners << "\n\tPerdedores: " << losers << std::endl;
}

Score::~Score() {}
