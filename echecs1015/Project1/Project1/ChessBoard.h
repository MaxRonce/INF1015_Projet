
#include "Piece.h"
#include <vector>
#include <memory>


	class ChessBoard {
	public:
		ChessBoard();
		void show();
		std::shared_ptr<Piece> findPiece(char x, int y) const ;
		bool isCheckMate(std::shared_ptr<Piece> piece) ;
		bool isValidMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) ;
		void capturePiece(std::shared_ptr<Piece>& piece);
	private:
		std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
		bool caseIsOccupied(std::shared_ptr<Piece> piece);
		void createPieces();
		void deletePiece(std::shared_ptr<Piece> piece);
		bool isKing(Piece* piece) ;
		void modifyPosition(Piece& piece);
		bool isHorizontalMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination)  const;
		bool isVerticalMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) const;
		bool isDiagonalMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination)  const;
		bool isKnightMove(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) const ;
		int moveStep(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> destination) const;
		bool isQueen(Piece* piece) const;
		bool isRook(Piece* piece) const;
		bool isPawn(Piece* piece) const;
		bool isKnight(Piece* piece) const;
		bool isBishop(Piece* piece) const;
		void synchronise(); //Has to be implemented in GUIclass
		std::vector<std::shared_ptr<Piece>> pieces;
		std::vector<std::shared_ptr<Piece>> capturedPieces;
		void initialisation();
		char board[8][8] = {}; //[colonne] [ligne]
		std::vector<std::pair<char, int>> initialPositions;

	};
