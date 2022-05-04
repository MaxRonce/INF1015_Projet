/*
* TP6 INF1015
* \file   Rook.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Cr�� le 20 avril 2022
*/
#pragma once
#include "Rook.h"
#include <iostream>
#include <utility>
#include <vector>


Rook::Rook(Piece::Color color, char x, int y) {
	color_ = color;
	symbol_ = 'R';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
}


