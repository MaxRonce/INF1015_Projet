#include "Queen.h"
#include <iostream>
#include <utility>



Queen::Queen(std::string color, char x, int y) {
	color_ = color;
	symbol_ = 'Q';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
}


