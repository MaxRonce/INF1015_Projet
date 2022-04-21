
#pragma once
#include <utility>
#include <map>

class Piece {
public:
	virtual bool mouvementValide() = 0;
	virtual void deplacer(char x, int y) = 0;
	std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
	std::pair<int, int> getPosition() const;
	std::pair<int, int> getPositionPrecedente() const;
	virtual void setPositionPrecedente() = 0;
	char getSymbole() const;
	virtual ~Piece() = default;
protected:
	std::pair<int, int> position;
	std::pair<int, int> positionPrecedente;
	char symbole = 'P';
};