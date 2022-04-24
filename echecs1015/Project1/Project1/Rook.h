#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook(std::string color);
	bool validMove(char x, int y) override;

};