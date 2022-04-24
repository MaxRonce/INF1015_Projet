#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include <iostream>
using namespace std;

ChessBoard::ChessBoard() {
	char board2[8][8] = {
		//  H    G    F    E    D    C    B    A 
		 { '0', '0', '0', '0', '0', '0', '0', '0',},//1
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//2
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//3
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//4
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//5
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//6
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//7
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//8
	};

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			board[i][j] = board2[i][j];
		}
	}

		
	
		King kingA;
		pieces.push_back(make_shared<King>(kingA));
		
		King kingB;
		pieces.push_back(make_shared<King>(kingB));
		
		Queen queenA;
		pieces.push_back(make_shared<Queen>(queenA));
		
		Queen queenB;
		pieces.push_back(make_shared<Queen>(queenB));
		
		Rook rookAA;
		pieces.push_back(make_shared<Rook>(rookAA));
		
		Rook rookAB;
		pieces.push_back(make_shared<Rook>(rookAB));
		
		Rook rookBA;
		pieces.push_back(make_shared<Rook>(rookBA));
	
		Rook rookBB;
		pieces.push_back(make_shared<Rook>(rookBA));
	
		initialisation();

};

void ChessBoard::initialisation() {
	pieces[0]->move('E', 1);
	pieces[0]->setPreviousPosition();
	pieces[1]->move('E', 8);
	pieces[1]->setPreviousPosition();
	pieces[2]->move('D', 1);
	pieces[2]->setPreviousPosition();
	pieces[3]->move('D', 8);
	pieces[3]->setPreviousPosition();
	pieces[4]->move('H', 1);
	pieces[4]->setPreviousPosition();
	pieces[5]->move('A', 1);
	pieces[5]->setPreviousPosition();
	pieces[6]->move('H', 8);
	pieces[6]->setPreviousPosition();
	pieces[7]->move('A', 8);
	pieces[7]->setPreviousPosition();
}
void ChessBoard::show() {
	synchronise();
	std::cout << "  H G F E D C B A \n";
	for (int i = 0; i < 8; ++i) {
		std::cout << i + 1 << "|";
		for (int j = 0; j < 8; ++j) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
};

void ChessBoard::modify(const Piece& piece) {
	board[piece.getPreviousPosition().second - 1][piece.getPreviousPosition().first - 1] = '0';
	board[piece.getPosition().second - 1][piece.getPosition().first - 1] = piece.getSymbol();
};

void ChessBoard::synchronise() {
	for (shared_ptr<Piece> i : pieces) {
		modify(*i.get());
	}
};
shared_ptr<Piece> ChessBoard::findPiece(char x, int y) {
	for (auto&& elem : pieces) {
		if (elem->getPosition().first == elem->map.find(x)->second && elem->getPosition().second == y) {
			return elem;
		}
	}
	return nullptr;
}

void ChessBoard::deletePiece(vector<shared_ptr<Piece>> vecteur, shared_ptr<Piece> piece) {
	for (int i = 0; i < vecteur.size(); ++i) {
		if (vecteur[i] == piece) {
			vecteur.erase(vecteur.begin() + i);
		}
	}
}

bool ChessBoard::isOccupied(const std::pair<int, int>& position)
{
	if (board[position.second][this->map.find(position.first)->second] != '0') {
		return true;
	}
	return false;
}
bool ChessBoard::isKing(Piece* piece) {
	auto ptr = dynamic_cast<King*>(piece);
	if (ptr != nullptr) {
		return true;
	}
	return false;
}
bool ChessBoard::isQueen(Piece* piece) {
	auto ptr = dynamic_cast<Queen*>(piece);
	if (ptr != nullptr) {
		return true;
	}
	return false;
}
bool ChessBoard::isRook(Piece* piece) {
	auto ptr = dynamic_cast<Rook*>(piece);
	if (ptr != nullptr) {
		return true;
	}
	return false;
}