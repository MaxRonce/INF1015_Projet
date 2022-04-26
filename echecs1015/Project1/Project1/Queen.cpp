/*
* TP6 INF1015
* \file   Queen.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#include "Queen.h"
#include <iostream>
#include <utility>



Queen::Queen(std::string color, char x, int y) {
	color_ = color;
	symbol_ = 'Q';
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;
}


