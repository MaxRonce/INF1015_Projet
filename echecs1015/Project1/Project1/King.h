#pragma once
#include "Piece.h"


class King : public Piece {
public:
	King(std::string color, char x, int y);
	~King();

private:
	static int inline compteurInstance_;


};

