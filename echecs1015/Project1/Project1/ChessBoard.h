
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
		int charToInt(char coord) const;

	private:
		std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
		bool caseIsOccupied(std::shared_ptr<Piece> piece);
		void createPieces();
		void deletePiece(std::shared_ptr<Piece> piece);
		void modifyPosition(Piece& piece);
		void synchronise(); //Has to be implemented in GUIclass
		std::vector<std::shared_ptr<Piece>> pieces_;
		std::vector<std::shared_ptr<Piece>> capturedPieces_;
		char board_[8][8] = {}; //[colonne] [ligne]

	};
