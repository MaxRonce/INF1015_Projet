#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include <iostream>
#include <algorithm>

ChessBoard::ChessBoard() {

	for (int i = 0; i < 8; ++i) 
	{
		for (int j = 0; j < 8; ++j) 
		{
			board_[i][j] = '0';
		}
	}
	createPieces();

}

void ChessBoard::createPieces() {
	//King creation
	pieces_.push_back(std::make_shared<King>(King("White",'E', 1)));
	pieces_.push_back(std::make_shared<King>(King("Black",'E', 8)));
	//Queen creation
	pieces_.push_back(std::make_shared<Queen>(Queen("White", 'D', 1)));
	pieces_.push_back(std::make_shared<Queen>(Queen("Black", 'D', 8)));
	//Rook creation
	pieces_.push_back(std::make_shared<Rook>(Rook("White", 'H', 1)));
	pieces_.push_back(std::make_shared<Rook>(Rook("Black", 'H', 8)));
	pieces_.push_back(std::make_shared<Rook>(Rook("White", 'A', 1)));
	pieces_.push_back(std::make_shared<Rook>(Rook("Black", 'A', 8)));
	//Bishop creation
	pieces_.push_back(std::make_shared<Bishop>(Bishop("White", 'F', 1)));
	pieces_.push_back(std::make_shared<Bishop>(Bishop("Black", 'F', 8)));
	pieces_.push_back(std::make_shared<Bishop>(Bishop("White", 'C', 1)));
	pieces_.push_back(std::make_shared<Bishop>(Bishop("Black", 'C', 8)));
	//Knight creation
	pieces_.push_back(std::make_shared<Knight>(Knight("White", 'G', 1)));
	pieces_.push_back(std::make_shared<Knight>(Knight("Black", 'G', 8)));
	pieces_.push_back(std::make_shared<Knight>(Knight("White", 'B', 1)));
	pieces_.push_back(std::make_shared<Knight>(Knight("Black", 'B', 8)));
	//Pawn creation
	pieces_.push_back(std::make_shared<Pawn>(Pawn("White", 'A', 2)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("Black", 'A', 7)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("White",'B', 2)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("Black", 'B', 7)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("White", 'C', 2)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("Black", 'C', 7)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("White", 'D', 2)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("Black", 'D', 7)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("White", 'E', 2)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("Black", 'E', 7)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("White", 'F', 2)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("Black", 'F', 7)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("White",'G', 2)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("Black", 'G', 7)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("White", 'H', 2)));
	pieces_.push_back(std::make_shared<Pawn>(Pawn("Black", 'H', 7)));
	
}

void ChessBoard::show() {
	synchronise();
	std::cout << "  H G F E D C B A \n";
	for (int i = 0; i < 8; ++i) 
	{
		std::cout << i + 1 << "|";
		for (int j = 0; j < 8; ++j)
		{
			std::cout << board_[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void ChessBoard::modifyPosition(Piece& piece) {
	board_[piece.getPreviousPosition().second - 1][piece.getPreviousPosition().first - 1] = '0';
	board_[piece.getPosition().second - 1][piece.getPosition().first - 1] = piece.getSymbol();
}

//synchronise() is used to update the board each time we change a piece's position, it updates the printed board
void ChessBoard::synchronise() {
	for (std::shared_ptr<Piece> i : pieces_)
	{
		modifyPosition(*i.get());
	}
}

std::shared_ptr<Piece> ChessBoard::findPiece(char x, int y)  const {
	for (auto&& elem : pieces_) 
	{
		if (elem->getPosition().first == elem->map.find(x)->second && elem->getPosition().second == y) 
		{
			return elem;
		}
	}
	return nullptr;
}

void ChessBoard::deletePiece(std::shared_ptr<Piece> piece) {
	for (int i = 0; i < pieces_.size(); ++i) 
	{
		if (pieces_[i] == piece) 
		{
			pieces_.erase(pieces_.begin() + i);
		}
	}
}

bool ChessBoard::caseIsOccupied(std::pair<int, int> destination)
{
	auto piece = findPiece(intToChar(destination.first), destination.second);
	if (piece != nullptr)
	{
		return true;
	}

	return false;
}

void ChessBoard::capturePiece(std::shared_ptr<Piece>& piece) {
	if (piece != nullptr) 
	{
		capturedPieces_.push_back(pieces_[0]);
		deletePiece(piece);
	}

}

namespace isPiece {
	bool isQueen(Piece* piece) {

		auto ptr = dynamic_cast<Queen*>(piece);
		if (ptr != nullptr) 
		{
			return true;
		}
		return false;

	};
	bool isRook(Piece* piece) {

		auto ptr = dynamic_cast<Rook*>(piece);
		if (ptr != nullptr)
		{
			return true;
		}
		return false;

	}
	bool isPawn(Piece* piece) {
		auto ptr = dynamic_cast<Pawn*>(piece);
		if (ptr != nullptr) 
		{

			return true;

		}
		return false;

	}
	bool isKnight(Piece* piece) {
		auto ptr = dynamic_cast<Knight*>(piece);
		if (ptr != nullptr) 
		{
			return true;
		}
		return false;

	}
	bool isBishop(Piece* piece) {
		auto ptr = dynamic_cast<Bishop*>(piece);
		if (ptr != nullptr)
		{

			return true;

		}
		return false;

	}
	bool isKing(Piece* piece) {
		auto ptr = dynamic_cast<King*>(piece);
		if (ptr != nullptr) 
		{

			return true;

		}
		return false;

	}
}

bool ChessBoard::isCheckMate(std::shared_ptr<Piece> piece) {
	using namespace isPiece;
	if (isKing(piece.get()))
	{

		return true;

	}
	return false;
}

namespace pieceMovements {
	bool isHorizontalMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) {
		return pieceToMove->getPosition().second == destination.second;
	}

	bool isVerticalMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) {
		return pieceToMove->getPosition().first == destination.first;
	}

	bool isDiagonalMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) {
		int verticalDifference = destination.second - pieceToMove->getPosition().second;
		int horizontalDifference = destination.first - pieceToMove->getPosition().first;

		return abs(verticalDifference) == abs(horizontalDifference);
	}

	bool isKnightMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) {
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

	int moveStep(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) {
		using namespace pieceMovements;
		if (isVerticalMove(pieceToMove, destination))
		{
			return abs(destination.second - pieceToMove->getPosition().second);
		}
		else if (isHorizontalMove(pieceToMove, destination))
		{
			return abs(destination.first - pieceToMove->getPosition().first);
		}
		else if (isDiagonalMove(pieceToMove, destination))
		{
			// We've already verified that this is a diagonal move, so we can just return the difference along one axis
			return abs(destination.first - pieceToMove->getPosition().first);
		}
		else
		{
			// Measuring non-linear distance is essentially undefined, so we'll return -1
			return -1;
		}
	}
}

bool ChessBoard::isValidMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) {
	using namespace isPiece;
	using namespace pieceMovements;
	bool validKingMove = isDiagonalMove(pieceToMove, destination)
		|| isHorizontalMove(pieceToMove, destination)
		|| isVerticalMove(pieceToMove, destination);
	if (isKing(pieceToMove.get())) 
	{
		return validKingMove && (moveStep(pieceToMove, destination) == 1) && !caseIsOccupiedSameColor(pieceToMove, destination);
	}
	else if (isQueen(pieceToMove.get())) 
	{
		return true;
	}
	else if (isRook(pieceToMove.get())) 
	{
		return isHorizontalMove(pieceToMove, destination) || isVerticalMove(pieceToMove, destination) && !caseIsOccupiedSameColor(pieceToMove, destination);
	}
	else if (isBishop(pieceToMove.get())) 
	{
		return isDiagonalMove(pieceToMove, destination) && !caseIsOccupiedSameColor(pieceToMove, destination);
	}
	else if (isKnight(pieceToMove.get())) 
	{
		return isKnightMove(pieceToMove, destination) && !caseIsOccupiedSameColor(pieceToMove, destination);
	}
	else if (isPawn(pieceToMove.get()))
	{
		//The Only Time where the previousPosition equals currentPosition is in the beginning
		bool beginning = (pieceToMove->getPosition() == pieceToMove->getPreviousPosition());
		if (beginning) {
			return isVerticalMove(pieceToMove, destination) && ((moveStep(pieceToMove, destination) == 2 || moveStep(pieceToMove, destination) == 1)) && !caseIsOccupiedSameColor(pieceToMove, destination);
		}
		else {
			if (caseIsOccupied(destination)) 
			{
				return isDiagonalMove(pieceToMove, destination) && (moveStep(pieceToMove, destination) == 1) && !caseIsOccupiedSameColor(pieceToMove, destination);
			}
			else 
			{
				return isVerticalMove(pieceToMove, destination) && (moveStep(pieceToMove, destination) == 1) && !caseIsOccupiedSameColor(pieceToMove, destination);
			}
		}
	}
	return false;
}

int ChessBoard::charToInt(char coord) const {
	return map.find(coord)->second;
}

bool ChessBoard::caseIsOccupiedSameColor(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) {
	auto piece = findPiece(intToChar(destination.first), destination.second);
	if (piece!=nullptr && pieceToMove->getColor()==piece->getColor())
	{
		return true;
	}

	return false;
}

char ChessBoard::intToChar(int x) {
	char foundKey = 0;
	auto lambda = [&](const std::pair<char, int>& pair) {
		return pair.second == x;
	};
	auto itr = std::find_if(std::begin(map), std::end(map), lambda);
	if (itr != std::end(map))
	{
		foundKey = itr->first;
	}
	return foundKey;
};