/*
* TP6 INF1015
* \file   Pawn.hpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "Piece.h"


class Pawn : public Piece
{
public:
	Pawn(Piece::Color color, char x, int y);
};
