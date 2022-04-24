#include "Rook.h"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

Rook::Rook(std::string color) {
	color_ = color;
	symbol = 'R';
}
bool Rook::validMove(char i, int y) {
	int x = this->map.find(i)->second;
	int step = 0;
	if (x - position.first == 0) {
		step = abs(y - position.second);
	}
	else {
		step = abs(x - position.first);
	}
	mouvementsAutorises = { { x, y - step }, { x , y + step }, { x - step, y }, { x + step, y } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	return false;

};

