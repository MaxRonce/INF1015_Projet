/*
* TP6 INF1015
* \file   Pawn.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#include "Pawn.h"

Pawn::Pawn(std::string color, char x, int y) {
	color_ = color;
	symbol_ = 'P';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
}



