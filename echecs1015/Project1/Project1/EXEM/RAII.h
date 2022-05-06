
#pragma once
#include "ChessBoard.h"
#include "Piece.h"

class RAII
{
	RAII(ChessBoard* chessBoard);
	void addPiece(std::shared_ptr<Piece> piece);
	~RAII();
private:
	ChessBoard* chessBoard_;
	std::vector<std::shared_ptr<Piece>> addedPieces_;
};

