#pragma once
#include "Piece.h"

class King: public Piece {
public:
	King();
	bool validMove() override;
	void move(char x, int y) override;
	~King();

private:

	static int inline compteurInstance;


};