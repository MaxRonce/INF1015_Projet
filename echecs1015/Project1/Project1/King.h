#pragma once
#include "Piece.h"

class King : public Piece {
public:
	King(std::string color);
	bool validMove(char x, int y) override;
	~King();

private:

	static int inline compteurInstance;


};