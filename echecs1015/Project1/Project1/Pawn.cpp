/*
* TP6 INF1015
* \file   Pawn.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Cr�� le 20 avril 2022
*/
#pragma once
#include "Pawn.h"

Pawn::Pawn(Piece::Color color, char x, int y) {
	color_ = color;
	symbol_ = 'P';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
}



