#pragma once
#include "Piece.h"

class Tour : public Piece {
public:
	Tour();
	bool mouvementValide() override;
	void deplacer(char x, int y) override;
	void setPositionPrecedente() override;

};