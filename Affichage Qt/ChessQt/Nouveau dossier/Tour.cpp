#include "Tour.h"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

bool Tour::mouvementValide(int pas) {

	std::vector<pair<int, int>> mouvementsAutorises{ { x_ , y_ - pas }, { x_ , y_ + pas }, { x_ - pas, y_ }, { x_ + pas, y_ } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	else {
		if (*mouvementsAutorises.end() == position) {
			return true;
		}
		return false;
	}

};

void Tour::deplacer(char x, int y) {
	positionPrecedente = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;
};

const std::pair<int, int> Tour::getPosition() const {
	return position;
};

const std::pair<int, int> Tour::getPositionPrecedente() const {
	return this->positionPrecedente;
};

void Tour::setPositionPrecedente() {
	positionPrecedente = getPosition();
};

const char Tour::getSymbole() const {
	return symbole;
};