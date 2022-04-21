#pragma once
#include "Piece.h"

class Roi : public Piece {
public:
	Roi();
	bool mouvementValide() override;
	void deplacer(char x, int y) override;
	void setPositionPrecedente() override;
	~Roi();

private:

	static int inline compteurInstance;


};