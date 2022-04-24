#pragma once
#include "Piece.h"

class Bishop: public Piece
{
	public:
	Bishop(std::string color);
	bool validMove(char x, int y) override;
};

