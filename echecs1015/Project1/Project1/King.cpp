#include "King.h"
#include "InstancesKingException.h"
#include <iostream>
#include <utility>
#include <vector>

King::King(std::string color)
{
	color_ = color;
	symbol = 'K';
	if (compteurInstance > 2) {
		throw InstancesKingException("More than 2 Instances of KING");
	}
	++compteurInstance;
};

King::~King() { --compteurInstance; };



