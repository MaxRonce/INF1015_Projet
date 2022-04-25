#include "Game.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

Game::Game():
chessBoard_(new ChessBoard){
}
void Game::start() {
	gameGUI();
}
namespace userUI {
	std::shared_ptr<Piece> userChoosePiece(ChessBoard* chessBoard) {
		char x = 0;
		int y = 0;
		cout << "\nPlease Choose Piece To Move :\n";
		cin >> x >> y;
		auto piece = chessBoard->findPiece(x, y);
		while (piece == nullptr) {
			cout << "\nInvalid Piece, Please Insert Valid Piece : \n";
			cin >> x >> y;
			piece = chessBoard->findPiece(x, y);
		}
		return piece;
	}
}
void Game::gameGUI() {
	using namespace userUI;
	try {
		std::cout << "Welcome Player, To Chess Game\n";
		while (!end_) {
			chessBoard_->show();
			auto piece = userChoosePiece(chessBoard_);
			processEvent(piece);
			system("CLS");
		}
		cout << "Game Over, Check Mate";
	}
	catch (InstancesKingException& except) {
		cout << "Execution Error : " << except.what() << endl;
	}
}
namespace coordination{
	std::pair<int, int> destionationCoord(ChessBoard* chessBoard, char x, int y) {
		std::shared_ptr<Piece> attackedPiece = attackedPiece = chessBoard->findPiece(x, y); ;
		if (attackedPiece != nullptr) {
			return  {attackedPiece->getPosition().first, attackedPiece->getPosition().second };
		}
		else {
			return { chessBoard->charToInt(x), y };
		}
	}

}

void Game::processEvent(shared_ptr<Piece> piece) {
	using namespace coordination;
	char x = 0;
	int y = 0;
	std::pair<int, int> destination;
	cout << "\nYour Next Move : \n";
	cin >> x >> y;
	auto attackedPiece = chessBoard_->findPiece(x, y);
	destination = destionationCoord(chessBoard_, x, y);
	while (!chessBoard_->isValidMove(piece, destination)) {
		cout << "\nInvalid Move, Please Insert Valid Move : \n";
		cin >> x >> y;
		destination = destionationCoord(chessBoard_, x, y);
	}
	chessBoard_->capturePiece(attackedPiece);
	piece->move(x, y);
	if (chessBoard_->isCheckMate(attackedPiece)){
		this->end_ = true;
	}
}