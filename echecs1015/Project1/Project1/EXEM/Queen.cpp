
#pragma once
#include "Queen.h"
#include <iostream>
#include <utility>


Queen::Queen(Piece::Color color, char x, int y) {
	color_ = color;
	symbol_ = 'Q';
    position_.first = map.find(x)->second-1;
    position_.second = y-1;
	previousPosition_ = position_;
}


