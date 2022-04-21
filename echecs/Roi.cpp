#include "Roi.h"
#include "InstancesRoiException.h"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
Roi::Roi()
{
	symbole = 'K';
	if (compteurInstance > 2) {
		throw InstancesRoiException("More than 2 Instances of KING");
	}
	++compteurInstance;
};

Roi::~Roi() { --compteurInstance; };

bool Roi::mouvementValide() {
	int pas = 1;
	int x = position.first;
	int y = position.second;
	std::vector<pair<int, int>> mouvementsAutorises{ {x, y - pas }, {x , y + pas }, {x - pas, y}, {x + pas, y }, {x - pas, y - pas }, {x + pas, y + pas }, {x - pas, y + pas}, {x + pas, y - pas } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	position = positionPrecedente;
	return false;

};

void Roi::deplacer(char x, int y) {
	positionPrecedente = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;

};


void Roi::setPositionPrecedente() {
	positionPrecedente = getPosition();
};

