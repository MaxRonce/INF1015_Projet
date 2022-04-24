#include "King.h"
#include "InstancesKingException.h"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
King::King()
{
	symbol = 'K';
	if (compteurInstance > 2) {
		throw InstancesKingException("More than 2 Instances of KING");
	}
	++compteurInstance;
};

King::~King() { --compteurInstance; };

bool King::validMove() {
	int pas = 1;
	int x = position.first;
	int y = position.second;
	std::vector<pair<int, int>> mouvementsAutorises{ {x, y - pas }, {x , y + pas }, {x - pas, y}, {x + pas, y }, {x - pas, y - pas }, {x + pas, y + pas }, {x - pas, y + pas}, {x + pas, y - pas } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	position = previousPosition;
	return false;

};

void King::move(char x, int y) {
	previousPosition = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;

};




