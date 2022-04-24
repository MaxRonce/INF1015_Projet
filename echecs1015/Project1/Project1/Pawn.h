#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn(std::string color);
	bool validMove(char x, int y) override;
};
