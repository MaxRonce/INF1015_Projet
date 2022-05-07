/*
* TP6 INF1015
* \file  Knight.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "Knight.h"

Knight::Knight(Piece::Color color, char x, int y) {
    color_ = color;
    position_.first = map.find(x)->second-1;
    position_.second = y-1;
    previousPosition_ = position_;
    symbol_ = 'C';
}


