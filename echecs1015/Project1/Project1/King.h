/*
* TP6 INF1015
* \file  King.hpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Cr�� le 20 avril 2022
*/#pragma once
#include "Piece.h"


class King : public Piece {
public:
	King(std::string color, char x, int y);
	~King();

private:
	static int inline compteurInstance_;


};

