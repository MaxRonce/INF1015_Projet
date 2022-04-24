#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
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
	createPieces();
	initialPositions = {
		{'E', 1}, {'E', 8 },{'D', 1}, {'D', 8},{'H', 1}, 
		{'H', 8 },{'A', 1}, {'A', 8 },{'F', 1}, {'F', 8 },
		{'C', 1}, {'C', 8 },{'G', 1}, {'G', 8 },{'B', 1}, 
		{'B', 8 },{'A', 2}, {'A', 7 },{'B', 2}, {'B', 7 },
		{'C', 2}, {'C', 7 },{'D', 2}, {'D', 7 },{'E', 2},
		{'E', 7 },{'F', 2},{'F', 7 },{'G', 2}, {'G', 7 },
		{'H', 2}, {'H',7 }
	};
	initialisation();

};

void ChessBoard::createPieces() {
	pieces.push_back(make_shared<King>(King("White")));
	pieces.push_back(make_shared<King>(King("Black")));
	pieces.push_back(make_shared<Queen>(Queen("White")));
	pieces.push_back(make_shared<Queen>(Queen("Black")));
	for (int i = 0; i < 2; ++i) {
		pieces.push_back(make_shared<Rook>(Rook("White")));
		pieces.push_back(make_shared<Rook>(Rook("Black")));
	}
	for (int i = 0; i < 2; ++i) {
		pieces.push_back(make_shared<Bishop>(Bishop("White")));
		pieces.push_back(make_shared<Bishop>(Bishop("Black")));
	}
	for (int i = 0; i < 2; ++i) {
		pieces.push_back(make_shared<Knight>(Knight("White")));
		pieces.push_back(make_shared<Knight>(Knight("Black")));
	}

	for (int i = 0; i < 8; ++i) {
		pieces.push_back(make_shared<Pawn>(Pawn("White")));
		pieces.push_back(make_shared<Pawn>(Pawn("Black")));
	}

}

void ChessBoard::initialisation() {
	for (int i = 0; i < pieces.size(); ++i) {
		pieces[i]->move(initialPositions[i].first, initialPositions[i].second);
		pieces[i]->setPreviousPosition();
	}

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

void ChessBoard::deletePiece(shared_ptr<Piece> piece) {
	for (int i = 0; i < pieces.size(); ++i) {
		if (pieces[i] == piece) {
			pieces.erase(pieces.begin() + i);
		}
	}
}

bool ChessBoard::caseIsOccupied(const shared_ptr<Piece> piece)
{
	if (board[piece->getPosition().second][piece->getPosition().first] != '0') {
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

void ChessBoard::capturePiece(shared_ptr<Piece> piece) {
	if (piece != nullptr) {
		capturedPieces.push_back(piece);
		deletePiece(piece);
	}
	//for debugging
	/*for (auto&& elem : capturedPieces) {
		cout << elem->getSymbol() << elem->getPosition().first << " " << elem->getPosition().second << endl;
	}
	cout << endl;*/
	/*for (auto&& elem : pieces) {
		cout << elem->getSymbol() << elem->getPosition().first << " " << elem->getPosition().second << endl;
	}*/
}

bool ChessBoard::isCheckMate(std::shared_ptr<Piece> piece) {
	if (isKing(piece.get())) {
		return true;

	}
	return false;
}