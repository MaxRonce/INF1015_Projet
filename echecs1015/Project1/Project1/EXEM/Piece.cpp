/*
* TP6 INF1015
* \file   Pawn.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "Piece.h"

Piece::Piece(Color color, char x, int y) {
	color_ = color;
    position_.first = map.find(x)->second-1;
    position_.second = y-1;
	previousPosition_ = position_;

}

std::pair<int, int> Piece::getPosition() const {
	return position_;
}

void Piece::move(std::pair<int, int> destination) {
	previousPosition_ = position_;
	position_.first = destination.first;
	position_.second = destination.second;
}

std::pair<int, int>Piece::getPreviousPosition() const {
	return previousPosition_;
};

char Piece::getSymbol() const {
	return symbol_;
};
void Piece::setColor(Color newColor) {
	color_ = newColor;
}

Piece::Color Piece::getColor() const {
	return color_;
}

bool Piece::firstMove() {
	if (position_ != previousPosition_) {
		return false;
	}
	return true;
}
void Piece::setPosition(std::pair<int, int> pos){
   position_=pos;
}
void Piece::setPreviousPosition(std::pair<int, int> pos){
   previousPosition_=pos;
}

