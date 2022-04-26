/*
* TP6 INF1015
* \file   Pawn.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "Piece.h"

Piece::Piece(std::string color, char x, int y) {
	color_ = color;
	position_.first = map.find(x)->second;
	position_.second = y;
	previousPosition_ = position_;

}

std::pair<int, int> Piece::getPosition() const {
	return position_;
}

void Piece::move(char x, int y) {
	previousPosition_ = position_;
	auto coordonnees = map.find(x);
	position_.first = coordonnees->second;
	position_.second = y;
}

std::pair<int, int>Piece::getPreviousPosition() const {
	return previousPosition_;
};

char Piece::getSymbol() const {
	return symbol_;
};
void Piece::setColor(std::string newColor) {
	color_ = newColor;
}

std::string Piece::getColor() const {
	return color_;
}
