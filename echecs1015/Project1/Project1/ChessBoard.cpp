#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include <iostream>

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
	initialPositions = {
		{'E', 1}, {'E', 8 },{'D', 1}, {'D', 8},{'H', 1}, 
		{'H', 8 },{'A', 1}, {'A', 8 },{'F', 1}, {'F', 8 },
		{'C', 1}, {'C', 8 },{'G', 1}, {'G', 8 },{'B', 1}, 
		{'B', 8 },{'A', 2}, {'A', 7 },{'B', 2}, {'B', 7 },
		{'C', 2}, {'C', 7 },{'D', 2}, {'D', 7 },{'E', 2},
		{'E', 7 },{'F', 2},{'F', 7 },{'G', 2}, {'G', 7 },
		{'H', 2}, {'H',7 }
	};

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			board[i][j] = board2[i][j];
		}
	}
	createPieces();
	initialisation();

};

void ChessBoard::createPieces() {
	pieces.push_back(std::make_shared<King>(King("White")));
	pieces.push_back(std::make_shared<King>(King("Black")));
	pieces.push_back(std::make_shared<Queen>(Queen("White")));
	pieces.push_back(std::make_shared<Queen>(Queen("Black")));
	int pairRook = 2;
	int pairBishop = 2;
	int pairKnight = 2;
	int pairPawn = 8;
	for (int i = 0; i < pairRook; ++i) {
		pieces.push_back(std::make_shared<Rook>(Rook("White")));
		pieces.push_back(std::make_shared<Rook>(Rook("Black")));
	}
	for (int i = 0; i < pairBishop; ++i) {
		pieces.push_back(std::make_shared<Bishop>(Bishop("White")));
		pieces.push_back(std::make_shared<Bishop>(Bishop("Black")));
	}
	for (int i = 0; i < pairKnight; ++i) {
		pieces.push_back(std::make_shared<Knight>(Knight("White")));
		pieces.push_back(std::make_shared<Knight>(Knight("Black")));
	}

	for (int i = 0; i < pairPawn; ++i) {
		pieces.push_back(std::make_shared<Pawn>(Pawn("White")));
		pieces.push_back(std::make_shared<Pawn>(Pawn("Black")));
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

void ChessBoard::initialisation() {
	for (int i = 0; i < pieces.size(); ++i) {
		pieces[i]->move(initialPositions[i].first, initialPositions[i].second);
		pieces[i]->setPreviousPosition();
	}
};


void ChessBoard::modifyPosition(Piece& piece) {
	board[piece.getPreviousPosition().second - 1][piece.getPreviousPosition().first - 1] = '0';
	board[piece.getPosition().second - 1][piece.getPosition().first - 1] = piece.getSymbol();
};

//synchronise() is used to update the board each time we change a piece's position, it updates the printed board
void ChessBoard::synchronise() { 
	for (std::shared_ptr<Piece> i : pieces) {
		modifyPosition(*i.get());
	}
};

std::shared_ptr<Piece> ChessBoard::findPiece(char x, int y)  const{
	for (auto&& elem : pieces) {
		if (elem->getPosition().first == elem->map.find(x)->second && elem->getPosition().second == y) {
			return elem;
		}
	}
	return nullptr;
}

void ChessBoard::deletePiece(std::shared_ptr<Piece> piece) {
	for (int i = 0; i < pieces.size(); ++i) {
		if (pieces[i] == piece) {
			pieces.erase(pieces.begin() + i);
		}
	}
}

bool ChessBoard::caseIsOccupied(std::shared_ptr<Piece> piece) 
{
	if (board[piece->getPosition().second][piece->getPosition().first] != '0') {
		return true;
	}
	return false;
}


void ChessBoard::capturePiece(std::shared_ptr<Piece>& piece) {
	if (piece != nullptr) {
		capturedPieces.push_back(pieces[0]);
		deletePiece(piece);
	}
}
bool ChessBoard::isKing(Piece* piece)  {
	auto ptr = dynamic_cast<King*>(piece);
	if (ptr != nullptr) {
		return true;
	}
	return false;
}

bool ChessBoard::isCheckMate(std::shared_ptr<Piece> piece) {
	if (isKing(piece.get())) {
		return true;

	}
	return false;
}

bool ChessBoard::isHorizontalMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) const {
	return pieceToMove->getPosition().second == destination.second;
}

bool ChessBoard::isVerticalMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination)  const {
	return pieceToMove->getPosition().first == destination.first;
}
bool ChessBoard::isDiagonalMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination)  const {
	int verticalDifference = destination.second - pieceToMove->getPosition().second;
	int horizontalDifference = destination.first-pieceToMove->getPosition().first;

	return abs(verticalDifference) == abs(horizontalDifference);
}

int ChessBoard::moveStep(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) const {
	if (isVerticalMove(pieceToMove, destination))
	{
		return abs(destination.second - pieceToMove->getPosition().second);
	}
	else if (isHorizontalMove(pieceToMove, destination))
	{
		return abs(destination.first -pieceToMove->getPosition().first);
	}
	else if (isDiagonalMove(pieceToMove, destination))
	{
		// We've already verified that this is a diagonal move, so we can just return the difference along one axis
		return abs(destination.first-pieceToMove->getPosition().first);
	}
	else
	{
		// Measuring non-linear distance is essentially undefined, so we'll return -1
		return -1;
	}
}

bool ChessBoard::isKnightMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) const {
	int verticalDifference = abs(destination.second - pieceToMove->getPosition().second);
	int horizontalDifference = abs(destination.first - pieceToMove->getPosition().first);

	if ((verticalDifference == 2 && horizontalDifference == 1) || (verticalDifference == 1 && horizontalDifference == 2))
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool ChessBoard::isQueen(Piece* piece)  const {
	auto ptr = dynamic_cast<Queen*>(piece);
	if (ptr != nullptr) {
		return true;
	}
	return false;
}
bool ChessBoard::isRook(Piece* piece)   const {
	auto ptr = dynamic_cast<Rook*>(piece);
	if (ptr != nullptr) {
		return true;
	}
	return false;
}
bool ChessBoard::isPawn(Piece* piece)  const {
	auto ptr = dynamic_cast<Pawn*>(piece);
	if (ptr != nullptr) {
		return true;
	}
	return false;
}
bool ChessBoard::isKnight(Piece* piece) const {
	auto ptr = dynamic_cast<Knight*>(piece);
	if (ptr != nullptr) {
		return true;
	}
	return false;
}
bool ChessBoard::isBishop(Piece* piece)  const {
	auto ptr = dynamic_cast<Bishop*>(piece);
	if (ptr != nullptr) {
		return true;
	}
	return false;
}

bool ChessBoard::isValidMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination)  {
	bool validKingMove = isDiagonalMove(pieceToMove, destination)
		|| isHorizontalMove(pieceToMove, destination)
		|| isVerticalMove(pieceToMove, destination);
	if (isKing(pieceToMove.get())) {
		if (validKingMove && (moveStep(pieceToMove, destination) == 1))
		{
			return true;
		}
	}
	if (isQueen(pieceToMove.get())) {
			return true;
	}
	if (isRook(pieceToMove.get())) {
		if (isHorizontalMove(pieceToMove, destination) || isVerticalMove(pieceToMove, destination)) {
			return true;
		}
	}
	if (isBishop(pieceToMove.get())) {
		if (isDiagonalMove(pieceToMove, destination)) {
			return true;
		}
	}
	if (isKnight(pieceToMove.get())) {
		return isKnightMove(pieceToMove, destination);
		
	}
	return false;
}