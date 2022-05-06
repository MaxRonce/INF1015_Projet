
#pragma once
#include "Pawn.h"

Pawn::Pawn(Piece::Color color, char x, int y) {
	color_ = color;
	symbol_ = 'P';
    position_.first = map.find(x)->second-1;
    position_.second = y-1;
	previousPosition_ = position_;
}



