#pragma once
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Piece.h"
#include "Rook.h"
#include <vector>
#include <memory>


    class ChessBoard {
    public:
        ChessBoard();
        void show();
        std::shared_ptr<Piece> findPiece(std::pair<int, int> coord);
        void move(std::pair<int, int> origin,std::pair<int, int> destination);
        bool isValidMove(std::pair<int, int> origin, std::pair<int, int> destination) ;
        void revertMove(std::pair<int, int> previous, std::shared_ptr<Piece> piece);
        void capturePiece(std::shared_ptr<Piece>& piece);
        int charToInt(char coord) const;
        void addPiece(std::shared_ptr<Piece> piece);
        void deletePiece(std::shared_ptr<Piece> piece);
        int moveStep(std::pair<int, int> origin, std::pair<int, int> destination);
        std::pair<int, int> getKingLocation(Piece::Color color);
        bool isPathClear(std::pair<int, int> origin, std::pair<int, int> toCoords);
        std::vector<std::pair<int, int>> getPiecesLocation(Piece::Color color);
        std::vector<std::pair<int, int>> getLocations();
    private:
        std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1} };
        bool caseIsOccupied(std::pair<int, int> destination);
        bool caseIsOccupiedSameColor(std::pair<int, int> origin, std::pair<int, int> toCoords);
        void createPieces();
        void modifyPosition(Piece& piece);
        void synchronise(); //Has to be implemented in GUIclass
        std::vector<std::shared_ptr<Piece>> capturedPieces_;
        char board_[8][8] = {}; //[colonne] [ligne]
        char intToChar(int x);
        std::vector<std::shared_ptr<Piece>> pieces_;
    };
