#include "Reine.h"
#include <iostream>
#include <utility>

using namespace std;

Reine::Reine() {
	symbole = 'Q';
}
bool Reine::mouvementValide() {

	return true;

};

void Reine::deplacer(char x, int y) {
	positionPrecedente = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;
};
void Reine::setPositionPrecedente() {
	positionPrecedente = getPosition();
};
