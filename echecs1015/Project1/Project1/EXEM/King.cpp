
#pragma once
#include "King.h"
#include "InstancesKingException.h"
#include <iostream>
#include <utility>
#include <vector>

King::King(Piece::Color color,char x, int y)
{
	color_ = color;
	symbol_ = 'K';
    position_.first = map.find(x)->second-1;
    position_.second = y-1;
    previousPosition_ = position_;
	if (compteurInstance_ > 2) 
	{
		throw InstancesKingException("More than 2 Instances of KING");
	}
	++compteurInstance_;
};

King::~King() { --compteurInstance_; };



