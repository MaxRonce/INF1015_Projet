/*
* TP6 INF1015
* \file   Pawn.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "Pawn.h"

Pawn::Pawn(Piece::Color color, char x, int y) {
	color_ = color;
	symbol_ = 'P';
    position_.first = map.find(x)->second-1;
    position_.second = y-1;
	previousPosition_ = position_;
}



