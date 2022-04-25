#pragma once
#include "Piece.h"


class King : public Piece {
public:
	King(std::string color);
	~King();

private:
	static int inline compteurInstance_;


};

