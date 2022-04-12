#include "Roi.h"
#include "InstancesRoiException.h"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
Roi::Roi()
{
	++compteurInstance;
	if (compteurInstance > 2)
		throw InstancesRoiException("Plus que 2 instances de Roi");
};

Roi::~Roi() { --compteurInstance; };

bool Roi::mouvementValide(int pas) {

	std::vector<pair<int, int>> mouvementsAutorises{ {x_ , y_ - pas }, {x_ , y_ + pas }, {x_ - pas, y_}, {x_ + pas, y_ }, {x_ - pas, y_ - pas }, {x_ + pas, y_ + pas }, {x_ - pas, y_ + pas}, {x_ + pas, y_ - pas } };
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

void Roi::deplacer(char x, int y) {
	positionPrecedente = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;

};

const std::pair<int, int> Roi::getPosition() const {
	return position;
};
const std::pair<int, int> Roi::getPositionPrecedente() const {
	return this->positionPrecedente;
};

void Roi::setPositionPrecedente() {
	positionPrecedente = getPosition();
};

const char Roi::getSymbole() const {
	return symbole;
};
