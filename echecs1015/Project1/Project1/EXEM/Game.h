
#pragma once
#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QObject>
#pragma pop()
#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Piece.h"
#include "InstancesKingException.h"

class Game : public QObject {
    Q_OBJECT
public: 
    Game()=default;
    //void start();
	// Movement
	bool castle(Piece::Color toMove, std::pair<int, int> from, std::pair<int, int> to);
	// Attributes
	bool isInCheck(Piece::Color defendingColor) const;
	bool isInCheckMate(Piece::Color defendingColor);
	bool isInStalemate(Piece::Color defendingColor);
	Piece::Color getTurn(int moveNumber) const;
	// Utilities
	std::string printColor(Piece::Color color);

public slots:
	void getInput(QString input);

signals:
    void sendResponse(QString response);
private:
	bool end_ = false;
    ChessBoard* board_ = new ChessBoard();
	std::string move1 = "";
	std::string move2 = "";
	Piece::Color guiTurn = Piece::Color::WHITE;
	void switchGuiTurn();
	void resetMoves();
	std::pair<int, int> inputToPos(std::string coords) const;

};

