#pragma once
#include "Piece.h"

std::pair<int, int> Piece::getPosition() const {
	return position;
};

std::pair<int, int>Piece::getPreviousPosition() const {
	return previousPosition;
};
char Piece::getSymbol() const {
	return symbol;
};
void Piece::setColor(std::string newColor) {
	color = newColor;
}
std::string Piece::getColor() const {
	return color;
}
void Piece::setPreviousPosition() {
	previousPosition = getPosition();
};