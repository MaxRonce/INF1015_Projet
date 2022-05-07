/*
* TP6 INF1015
* \file   Piece.hpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include <utility>
#include <string>
#include <map>
#include <vector>


class Piece {
public:
	enum class Color { WHITE, BLACK };
    Piece()=default;
	Piece(Color color, char x, int y);
	void move(std::pair<int, int> destination);
	std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
	std::pair<int, int> getPosition() const;
	std::pair<int, int> getPreviousPosition() const;
    void setPosition(std::pair<int, int> pos);
    void setPreviousPosition(std::pair<int, int> pos);
	char getSymbol() const;
	Color getColor() const;
	void setColor(Color newColor);
	virtual ~Piece() =  default;
	bool firstMove();

protected:
	std::pair<int, int> position_;
	std::pair<int, int> previousPosition_;
	char symbol_ = 'W';
	Color color_;
};
