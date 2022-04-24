#pragma once
#include <utility>
#include <string>
#include <map>

class Piece {
public:
	virtual bool validMove() = 0;
	virtual void move(char x, int y) = 0;
	std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
	std::pair<int, int> getPosition() const;
	std::pair<int, int> getPreviousPosition() const;
	void setPreviousPosition();
	char getSymbol() const;
	std::string getColor() const;
	void setColor(std::string newColor);
	virtual ~Piece() = default;
protected:
	std::pair<int, int> position;
	std::pair<int, int> previousPosition;
	char symbol = 'P';
	std::string color;
};