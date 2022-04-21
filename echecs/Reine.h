#pragma once
#include "Piece.h"

class Reine : public Piece {
public:
	Reine();
	bool mouvementValide() override;
	void deplacer(char x, int y) override;
	void setPositionPrecedente() override;
};