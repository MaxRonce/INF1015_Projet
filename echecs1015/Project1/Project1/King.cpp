#include "King.h"
#include "InstancesKingException.h"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
King::King(std::string color)
{
	color_ = color;
	symbol = 'K';
	if (compteurInstance > 2) {
		throw InstancesKingException("More than 2 Instances of KING");
	}
	++compteurInstance;
};

King::~King() { --compteurInstance; };

bool King::validMove(char  i, int y) {
	int x = this->map.find(i)->second;
	int step = 1;
	mouvementsAutorises = { {x, y - step }, {x , y + step }, {x - step, y}, {x + step, y }, {x - step, y - step }, {x + step, y + step }, {x - step, y + step}, {x + step, y - step } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	return false;

};


