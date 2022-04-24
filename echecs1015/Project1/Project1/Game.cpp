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
void Game::gameGUI() {
	try {
		std::cout << "Welcome Player, To Chess Game\n";
		while (!end) {
			chessBoard_->show();
			auto piece = userChoosePiece();
			processEvent(piece);
			system("CLS");
		}
		cout << "Game Over, Check Mate";
	}
	catch (InstancesKingException& except) {
		cout << "Execution Error : " << except.what() << endl;
	}
}
std::shared_ptr<Piece> Game::userChoosePiece() {
	char x = 0;
	int y = 0;
	cout << "\nPlease Choose Piece To Move :\n";
	cin >> x >> y;
	auto piece = chessBoard_->findPiece(x, y);
	while (piece == nullptr) {
		cout << "\nInvalid Piece, Please Insert Valid Move : \n";
		cin >> x >> y;
		piece = chessBoard_->findPiece(x, y);
	}
	return piece;
}

void Game::processEvent(shared_ptr<Piece> piece) {
	char x = 0;
	int y = 0;
	cout << "\nYour Next Move : \n";
	cin >> x >> y;
	while (!piece->validMove(x, y)) {
		cout << "\nInvalid Move, Please Insert Valid Move : \n";
		cin >> x >> y;
	}
	auto attackedPiece = chessBoard_->findPiece(x, y);
	chessBoard_->capturePiece(attackedPiece);
	piece->move(x, y);
	if (chessBoard_->isCheckMate(attackedPiece)){
		this->end = true;
	}
}
