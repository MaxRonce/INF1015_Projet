//#include <iostream>
#pragma once
#include <utility>
#include <map>
//#include <algorithm>

class Piece {
public:
	virtual bool mouvementValide(int pas) = 0;
	virtual void deplacer(char x, int y) = 0;
	std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
	virtual const std::pair<int, int> getPosition() const = 0;
	virtual const std::pair<int, int> getPositionPrecedente() const = 0;
	virtual void setPositionPrecedente() = 0;
	virtual const char getSymbole() const = 0;

private:
	std::pair<int, int> position;
	std::pair<int, int> positionPrecedente;
	char symbole = 'P';
	int x_ = 0;
	int y_ = 0;
};
