/*
* TP6 INF1015
* \file   Game.hpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Piece.h"
#include "InstancesKingException.h"

class Game {
public: 
	Game();
	void start();

private:
	void gameGUI();
	void processEvent(std::shared_ptr<Piece> piece);
	ChessBoard* chessBoard_;
	bool end_ = false;

};

