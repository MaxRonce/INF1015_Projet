#pragma once
#include "Piece.h"

std::pair<int, int> Piece::getPosition() const {
	return position;
};

std::pair<int, int>Piece::getPositionPrecedente() const {
	return this->positionPrecedente;
};
char Piece::getSymbole() const {
	return symbole;
};