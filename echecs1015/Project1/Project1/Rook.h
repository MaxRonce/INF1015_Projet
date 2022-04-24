#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
	Rook();
	bool validMove() override;
	void move(char x, int y) override;

};