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
		while (!end_) {
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
		cout << "\nInvalid Piece, Please Insert Valid Piece : \n";
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
	std::pair<int, int> destination;
	auto attackedPiece = chessBoard_->findPiece(x, y);
	if (attackedPiece!= nullptr) {
		destination = {attackedPiece->getPosition().first, attackedPiece->getPosition().second};
	}
	else {
		destination = { chessBoard_->charToInt(x), y};
	}
	while (!chessBoard_->isValidMove(piece, destination)) {
		cout << "\nInvalid Move, Please Insert Valid Move : \n";
		cin >> x >> y;
		attackedPiece = chessBoard_->findPiece(x, y);
		if (attackedPiece != nullptr) {
			destination = { attackedPiece->getPosition().first, attackedPiece->getPosition().second };
		}
		else {
			destination = { x, y };
		}
	}
	chessBoard_->capturePiece(attackedPiece);
	piece->move(x, y);
	if (chessBoard_->isCheckMate(attackedPiece)){
		this->end_ = true;
	}
}
