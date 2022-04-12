#include "Reine.h"
#include <iostream>
#include <utility>

using namespace std;
bool Reine::mouvementValide(int pas) {

	return true;

};

void Reine::deplacer(char x, int y) {
	positionPrecedente = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;
};

const std::pair<int, int> Reine::getPosition() const {
	return position;
};

const std::pair<int, int> Reine::getPositionPrecedente() const {
	return this->positionPrecedente;
};
void Reine::setPositionPrecedente() {
	positionPrecedente = getPosition();
};
const char Reine::getSymbole() const {
	return symbole;
};