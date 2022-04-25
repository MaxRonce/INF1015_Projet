#include "Rook.h"
#include <iostream>
#include <utility>
#include <vector>


Rook::Rook(std::string color, char x, int y) {
	color_ = color;
	symbol_ = 'R';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
}


