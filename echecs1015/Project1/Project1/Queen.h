#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
	Queen(std::string color);
	bool validMove(char x, int y) override;
};