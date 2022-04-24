#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
	Queen();
	bool validMove() override;
	void move(char x, int y) override;
};