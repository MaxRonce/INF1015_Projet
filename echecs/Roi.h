#pragma once
#include "Piece.h"

class Roi : public Piece {
public:
	Roi();
	bool mouvementValide(int pas) override;
	void deplacer(char x, int y) override;
	const std::pair<int, int> getPosition() const override;
	const std::pair<int, int> getPositionPrecedente() const override;
	void setPositionPrecedente() override;
	const char getSymbole() const override;
	~Roi();
	static int inline compteurInstance;

private:

	std::pair<int, int> positionPrecedente;
	std::pair<int, int> position;
	char symbole = 'K';
	int x_ = position.first;
	int y_ = position.second;

};