/*
* TP6 INF1015
* \file  King.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
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



