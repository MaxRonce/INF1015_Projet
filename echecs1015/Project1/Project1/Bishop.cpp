#pragma once
#include "Bishop.h"


Bishop::Bishop(std::string color) {
	color_ = color;
	symbol = 'B';
}
bool Bishop::validMove(char  i, int y){
	int x = this->map.find(i)->second;
	int step = 0;
	if (x - position.first == 0) {
		step = abs(y - position.second);
	}
	else {
		step = abs(x - position.first);
	}
	mouvementsAutorises = { { x-step, y - step }, { x- step , y + step }, { x + step, y+step }, { x +step, y -step } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	return false;

}
