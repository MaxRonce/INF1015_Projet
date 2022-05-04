/*
* TP6 INF1015
* \file   Game.hpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Piece.h"
#include "InstancesKingException.h"

class Game {
public: 
	Game();
	void start();
	// Movement
	bool castle(Piece::Color toMove, std::pair<int, int> from, std::pair<int, int> to);
	// Attributes
	bool isInCheck(Piece::Color defendingColor) const;
	bool isInCheckMate(Piece::Color defendingColor);
	bool isInStalemate(Piece::Color defendingColor);
	Piece::Color getTurn(int moveNumber) const;
	// Utilities
	std::string printColor(Piece::Color color);

	/* Qt Signaling
public slots:
	void getInput(QString input);

signals:
	void sendResponse(QString response);*/
private:
	bool end_ = false;
	ChessBoard* board_;
	//QString guimove;
	std::string move1 = "";
	std::string move2 = "";
	Piece::Color guiTurn = Piece::Color::WHITE;
	void switchGuiTurn();
	void resetMoves();
	std::pair<int, int> inputToPos(std::string coords) const;

};

