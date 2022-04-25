#include "Game.h"
#include <iostream>
#include <stdlib.h>


Game::Game():
chessBoard_(new ChessBoard){
}

void Game::start() {
	gameGUI();
}

namespace userUI {
	std::shared_ptr<Piece> choosePiece(ChessBoard* chessBoard) {
		char x = 0;
		int y = 0;
		std::cout << "\nPlease Choose Piece To Move :\n";
		std::cin >> x >> y;
		auto piece = chessBoard->findPiece(x, y);
		while (piece == nullptr) 
		{
			std::cout << "\nInvalid Piece, Please Insert Valid Piece : \n";
			std::cin >> x >> y;
			piece = chessBoard->findPiece(x, y);
		}
		return piece;
	}
}

void Game::gameGUI() {
	using namespace userUI;
	try {
		std::cout << "Welcome Player, To Chess Game\n";
		std::cout << "Please Insert Y Movement Then X Movement\n";
		std::cout << "Example : A2\n";
		std::cout << "Happy Game :)!\n";
		while (!end_)
		{
			chessBoard_->show();
			auto piece = choosePiece(chessBoard_);
			processEvent(piece);
			system("CLS");
		}
		std::cout << "Game Over, Check Mate";
	}
	catch (InstancesKingException& except) {
		std::cout << "Execution Error : " << except.what() << std::endl;
	}
}

namespace coordination{
	std::pair<int, int> destionationCoord(ChessBoard* chessBoard, char x, int y) {
		std::shared_ptr<Piece> attackedPiece = attackedPiece = chessBoard->findPiece(x, y); ;
		if (attackedPiece != nullptr)
		{
			return  {attackedPiece->getPosition().first, attackedPiece->getPosition().second };
		}
		else 
		{
			return { chessBoard->charToInt(x), y };
		}
	}

}

void Game::processEvent(std::shared_ptr<Piece> piece) {
	using namespace coordination;
	char x = 0;
	int y = 0;
	std::pair<int, int> destination;
	std::cout << "\nYour Next Move : \n";
	std::cin >> x >> y;
	auto attackedPiece = chessBoard_->findPiece(x, y);
	destination = destionationCoord(chessBoard_, x, y);
	while (!chessBoard_->isValidMove(piece, destination))
	{
		std::cout << "\nInvalid Move, Please Insert Valid Move : \n";
		std::cin >> x >> y;
		destination = destionationCoord(chessBoard_, x, y);
	}
	chessBoard_->capturePiece(attackedPiece);
	piece->move(x, y);
	if (chessBoard_->isCheckMate(attackedPiece))
	{
		this->end_ = true;
	}
}
