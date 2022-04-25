#pragma once
#include "Piece.h"

Piece::Piece(std::string color) {
	color_ = color;
};
std::pair<int, int> Piece::getPosition() const {
	return position;
};
void Piece::move(char x, int y) {
	previousPosition = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;
}


std::pair<int, int>Piece::getPreviousPosition() const {
	return previousPosition;
};
char Piece::getSymbol() const {
	return symbol;
};
void Piece::setColor(std::string newColor) {
	color_ = newColor;
}
std::string Piece::getColor() const {
	return color_;
}
