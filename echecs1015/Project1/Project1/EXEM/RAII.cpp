

#include "RAII.h"

RAII::RAII(ChessBoard* chessBoard) {
	chessBoard_ = chessBoard;
}

void RAII::addPiece(std::shared_ptr<Piece> piece) {
	chessBoard_->addPiece(piece);
	addedPieces_.push_back(piece);
}

RAII::~RAII() {
	for (auto it = addedPieces_.begin(); it != addedPieces_.end(); it++) {
		chessBoard_->deletePiece(*it);
	}
	addedPieces_.clear();

}
