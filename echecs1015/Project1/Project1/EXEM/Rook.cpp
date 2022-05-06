
#pragma once
#include "Rook.h"
#include <iostream>
#include <utility>
#include <vector>


Rook::Rook(Piece::Color color, char x, int y) {
	color_ = color;
	symbol_ = 'R';
    position_.first = map.find(x)->second-1;
    position_.second = y-1;
	previousPosition_ = position_;
}


