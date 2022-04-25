#include "Pawn.h"

Pawn::Pawn(std::string color, char x, int y) {
	color_ = color;
	symbol_ = 'P';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
}



