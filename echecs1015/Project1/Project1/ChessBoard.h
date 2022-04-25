
#include "Piece.h"
#include <vector>
#include <memory>

class ChessBoard {
public:
	ChessBoard();
	void show();
	std::shared_ptr<Piece> findPiece(char x, int y);
	bool isCheckMate(std::shared_ptr<Piece> piece);
	void capturePiece(std::shared_ptr<Piece> piece);
private:
	std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
	bool caseIsOccupied(const std::shared_ptr<Piece> piece);
	void createPieces();
	void deletePiece(std::shared_ptr<Piece> piece);
	bool isKing(Piece* piece);
	void modifyPosition (const Piece& piece);
	void synchronise(); //Has to be implemented in GUIclass
	std::vector<std::shared_ptr<Piece>> pieces;
	std::vector<std::shared_ptr<Piece>> capturedPieces;
	void initialisation();
	char board[8][8] = {}; //[colonne] [ligne]
	std::vector<std::pair<char, int>> initialPositions;

};