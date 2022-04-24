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
private:
	void gameGUI();
	std::shared_ptr<Piece> userChoosePiece();
	void processEvent(std::shared_ptr<Piece> piece);
	ChessBoard* chessBoard_;

};
