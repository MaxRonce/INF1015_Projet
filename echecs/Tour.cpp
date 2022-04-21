#include "Tour.h"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

Tour::Tour() {
	symbole = 'T';
}
bool Tour::mouvementValide() {
	int x = position.first;
	int y = position.second;
	int pas = abs(position.first - positionPrecedente.first);
	std::vector<pair<int, int>> mouvementsAutorises{ { x, y - pas }, { x , y + pas }, { x - pas, y }, { x + pas, y } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	position = positionPrecedente;
	return false;

};

void Tour::deplacer(char x, int y) {
	positionPrecedente = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;
};



void Tour::setPositionPrecedente() {
	positionPrecedente = getPosition();
};

