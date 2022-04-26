/*
* TP6 INF1015
* \file   Bishop.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "Bishop.h"


Bishop::Bishop(std::string color, char x, int y) {

	color_ = color;
	symbol_ = 'B';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
}

