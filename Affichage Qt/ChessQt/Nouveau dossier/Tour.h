#pragma once
#include "Piece.h"

class Tour : public Piece {
public:
	bool mouvementValide(int pas) override;
	void deplacer(char x, int y) override;
	const std::pair<int, int> getPosition() const override;
	const std::pair<int, int> getPositionPrecedente() const override;
	void setPositionPrecedente() override;
	const char getSymbole() const override;
private:

	std::pair<int, int> position;
	std::pair<int, int> positionPrecedente;
	char symbole = 'T';
	int x_ = position.first;
	int y_ = position.second;

};