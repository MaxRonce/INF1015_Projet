/*
* TP6 INF1015
* \file   RAII.hpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
    Rook(Piece::Color color, char x, int y);

};
