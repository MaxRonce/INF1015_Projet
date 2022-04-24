#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(std::string color);
	bool validMove(char x, int y) override;
};

