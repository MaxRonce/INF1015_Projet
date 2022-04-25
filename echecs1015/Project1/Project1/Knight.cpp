#include "Knight.h"

Knight::Knight(std::string color, char x, int y) {
	color_ = color;
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
	symbol_ = 'C';
}


