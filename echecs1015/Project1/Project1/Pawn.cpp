#include "Pawn.h"

Pawn::Pawn(std::string color) {
	color_ = color;
	symbol = 'P';
}
bool Pawn::validMove(char  i, int y) {
	int x = this->map.find(i)->second;
	int step = 0;
	if (previousPosition == position) {
		step = 2;
	}
	else {
			step = 1;

	}
	mouvementsAutorises = { { x + step, y } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	return false;

}


