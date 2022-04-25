#include "King.h"
#include "InstancesKingException.h"
#include <iostream>
#include <utility>
#include <vector>

King::King(std::string color)
{
	color_ = color;
	symbol_ = 'K';
	if (compteurInstance_ > 2) {
		throw InstancesKingException("More than 2 Instances of KING");
	}
	++compteurInstance_;
};

King::~King() { --compteurInstance_; };



