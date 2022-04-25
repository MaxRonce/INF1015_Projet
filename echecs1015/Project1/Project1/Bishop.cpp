#pragma once
#include "Bishop.h"


Bishop::Bishop(std::string color, char x, int y) {

	color_ = color;
	symbol_ = 'B';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
}

