
#include "Piece.h"
#include <vector>
#include <memory>

class ChessBoard {
public:
	ChessBoard();
	void show();
	std::shared_ptr<Piece> findPiece(char x, int y);
	bool caseIsOccupied(const std::shared_ptr<Piece> piece);
	bool isKing(Piece* piece);
	bool isQueen(Piece* piece);
	bool isRook(Piece* piece);
	void capturePiece(std::shared_ptr<Piece> piece);

private:
	std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
	void deletePiece(std::shared_ptr<Piece> piece);
	void modify(const Piece& piece);
	void synchronise();
	std::vector<std::shared_ptr<Piece>> pieces;
	std::vector<std::shared_ptr<Piece>> capturedPieces;
	void initialisation();
	char board[8][8] = {}; //[colonne] [ligne]

};