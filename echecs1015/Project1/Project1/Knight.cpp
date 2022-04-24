#include "Knight.h"

Knight::Knight(std::string color) {
	color_ = color;
	symbol = 'C';
}
bool Knight::validMove(char  x, int y) {
	int firstStepToL = 3;
	int secondStepToL = 1;
	mouvementsAutorises = {

		{ x - firstStepToL, y - secondStepToL },{ x - firstStepToL, y + secondStepToL },
		{ x - secondStepToL, y - firstStepToL },{ x + secondStepToL, y - firstStepToL },
		{ x - secondStepToL, y + firstStepToL },{ x + secondStepToL, y + firstStepToL },
		{ x + firstStepToL, y + secondStepToL }, { x + firstStepToL, y - secondStepToL }

	};

	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	return false;

}

