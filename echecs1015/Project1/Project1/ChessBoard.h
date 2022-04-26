/*
* TP6 INF1015
* \file   ChessBoard.hpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Cr�� le 20 avril 2022
*/
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
		void addPiece(std::shared_ptr<Piece> piece);
		void deletePiece(std::shared_ptr<Piece> piece);

	private:
		std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
		bool caseIsOccupied(std::pair<int, int> destination);
		bool caseIsOccupiedSameColor(std::shared_ptr<Piece> pieceToMove, std::pair<int, int> toCoords);
		void createPieces();
		void modifyPosition(Piece& piece);
		void synchronise(); //Has to be implemented in GUIclass
		std::vector<std::shared_ptr<Piece>> pieces_;
		std::vector<std::shared_ptr<Piece>> capturedPieces_;
		char board_[8][8] = {}; //[colonne] [ligne]
		char intToChar(int x);
	};
