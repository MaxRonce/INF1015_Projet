#pragma once
#include <utility>
#include <string>
#include <map>
#include <vector>

class Piece {
public:
	Piece() = default;
	Piece(std::string color);
	void move(char x, int y);
	std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
	std::pair<int, int> getPosition() const;
	std::pair<int, int> getPreviousPosition() const;
	char getSymbol() const;
	std::string getColor() const;
	void setColor(std::string newColor);
	void setPreviousPosition();
	virtual ~Piece() =  default;
protected:
	std::pair<int, int> position_;
	std::pair<int, int> previousPosition_;
	char symbol_ = 'W';
	std::string color_;
};