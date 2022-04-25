#include "King.h"
#include "InstancesKingException.h"
#include <iostream>
#include <utility>
#include <vector>

King::King(std::string color,char x, int y)
{
	color_ = color;
	symbol_ = 'K';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
	if (compteurInstance_ > 2) 
	{
		throw InstancesKingException("More than 2 Instances of KING");
	}
	++compteurInstance_;
};

King::~King() { --compteurInstance_; };



