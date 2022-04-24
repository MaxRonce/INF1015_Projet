#pragma once
#include <utility>
#include <string>
#include <map>
#include <vector>

class Piece {
public:
	Piece() = default;
	Piece(std::string color);
	virtual bool validMove(char x, int y) = 0;
	void move(char x, int y);
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
	std::vector<std::pair<int, int>> mouvementsAutorises;
	char symbol = 'W';
	std::string color_;
};