/*
* TP6 INF1015
* \file   ChessBoard.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "ChessBoard.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <QDebug>
ChessBoard::ChessBoard() {

   boardInit();

}
void ChessBoard::boardInit(){
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            board_[i][j] = '0';
        }
    }

}
void ChessBoard::defaultChess(){
  createPieces();
}

void ChessBoard::createPieces() {
    //King creation
   pieces_.push_back(std::make_shared<King>(King(Piece::Color::WHITE,'E', 1)));
    pieces_.push_back(std::make_shared<King>(King(Piece::Color::BLACK,'E', 8)));
    //Queen creation
    pieces_.push_back(std::make_shared<Queen>(Queen(Piece::Color::WHITE, 'D', 1)));
    pieces_.push_back(std::make_shared<Queen>(Queen(Piece::Color::BLACK, 'D', 8)));
    //Rook creation
    pieces_.push_back(std::make_shared<Rook>(Rook(Piece::Color::WHITE, 'H', 1)));
    pieces_.push_back(std::make_shared<Rook>(Rook(Piece::Color::BLACK, 'H', 8)));
    pieces_.push_back(std::make_shared<Rook>(Rook(Piece::Color::WHITE, 'A', 1)));
    pieces_.push_back(std::make_shared<Rook>(Rook(Piece::Color::BLACK, 'A', 8)));
    //Bishop creation
    pieces_.push_back(std::make_shared<Bishop>(Bishop(Piece::Color::WHITE, 'F', 1)));
    pieces_.push_back(std::make_shared<Bishop>(Bishop(Piece::Color::BLACK, 'F', 8)));
    pieces_.push_back(std::make_shared<Bishop>(Bishop(Piece::Color::WHITE, 'C', 1)));
    pieces_.push_back(std::make_shared<Bishop>(Bishop(Piece::Color::BLACK, 'C', 8)));
    //Knight creation
    pieces_.push_back(std::make_shared<Knight>(Knight(Piece::Color::WHITE, 'G', 1)));
    pieces_.push_back(std::make_shared<Knight>(Knight(Piece::Color::BLACK, 'G', 8)));
    pieces_.push_back(std::make_shared<Knight>(Knight(Piece::Color::WHITE, 'B', 1)));
    pieces_.push_back(std::make_shared<Knight>(Knight(Piece::Color::BLACK, 'B', 8)));
    //Pawn creation
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::WHITE, 'A', 2)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::BLACK, 'A', 7)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::WHITE,'B', 2)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::BLACK, 'B', 7)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::WHITE, 'C', 2)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::BLACK, 'C', 7)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::WHITE, 'D', 2)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::BLACK, 'D', 7)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::WHITE, 'E', 2)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::BLACK, 'E', 7)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::WHITE, 'F', 2)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::BLACK, 'F', 7)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::WHITE,'G', 2)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::BLACK, 'G', 7)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::WHITE, 'H', 2)));
    pieces_.push_back(std::make_shared<Pawn>(Pawn(Piece::Color::BLACK, 'H', 7)));

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
    for (auto&& i : pieces_)
    {
        modifyPosition(*i.get());
    }
}

//TODO : a la place dun char avoir une pair de <int, int>
std::shared_ptr<Piece> ChessBoard::findPiece(std::pair<int, int> coord) {
    for (auto&& elem: pieces_)
    {
        if (elem->getPosition().first == coord.first && elem->getPosition().second == coord.second)
        {
            return elem;
        }
    }
    return nullptr;
}

void ChessBoard::deletePiece(std::shared_ptr<Piece> piece) {

    auto it = std::find(pieces_.begin(), pieces_.end(), piece);
    pieces_.erase(it);
}


bool ChessBoard::caseIsOccupied(std::pair<int, int> destination)
{
    auto piece = findPiece(std::make_pair(destination.first, destination.second));
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

// TODO a la place de prendre pieceTomoe ca doit prendre une pair int int
namespace pieceMovements {
    bool isHorizontalMove(std::pair<int, int> origin, std::pair<int, int> destination) {
        return origin.second == destination.second;
    }

    bool isVerticalMove(std::pair<int, int> origin, std::pair<int, int> destination) {
        return origin.first == destination.first;
    }

    bool isDiagonalMove(std::pair<int, int> origin, std::pair<int, int> destination) {
        int verticalDifference = destination.second - origin.second;
        int horizontalDifference = destination.first - origin.first;

        return abs(verticalDifference) == abs(horizontalDifference);
    }

    bool isKnightMove(std::pair<int, int> origin, std::pair<int, int> destination) {
        int verticalDifference = abs(destination.second - origin.second);
        int horizontalDifference = abs(destination.first - origin.first);

        if ((verticalDifference == 2 && horizontalDifference == 1) || (verticalDifference == 1 && horizontalDifference == 2))
        {
            return true;
        }
        else
        {
            return false;
        }

    }

}
// TODO a la place de prendre pieceTomoe ca doit prendre une pair int int
int ChessBoard::moveStep(std::pair<int, int> origin, std::pair<int, int> destination) {
    using namespace pieceMovements;
    if (isVerticalMove(origin, destination))
    {
        return abs(destination.second - origin.second);
    }
    else if (isHorizontalMove(origin, destination))
    {
        return abs(destination.first - origin.first);
    }
    else if (isDiagonalMove(origin, destination))
    {
        // We've already verified that this is a diagonal move, so we can just return the difference along one axis
        return abs(destination.first - origin.first);
    }
    else
    {
        // Measuring non-linear distance is essentially undefined, so we'll return -1
        return -1;
    }
}
// TODO a la place de prendre pieceTomoe ca doit prendre une pair int int
bool ChessBoard::isValidMove(std::pair<int, int> origin, std::pair<int, int> destination) {
    using namespace isPiece;
    using namespace pieceMovements;
    bool validKingMove = isDiagonalMove(origin, destination)
        || isHorizontalMove(origin, destination)
        || isVerticalMove(origin, destination);
    //The Only Time where the previousPosition equals currentPosition is in the beginning
    bool beginning = (findPiece(origin)->getPosition() == findPiece(origin)->getPreviousPosition());
        if (isKing(findPiece(origin).get()))
        {
            return validKingMove && (moveStep(origin, destination) == 1) && !caseIsOccupiedSameColor(origin, destination) && isPathClear(origin,destination);
        }
        else if (isQueen(findPiece(origin).get()))
        {
            return  !caseIsOccupiedSameColor(origin, destination)&& isPathClear(origin,destination);
        }
        else if (isRook(findPiece(origin).get()))
        {
           return (isHorizontalMove(origin, destination) || isVerticalMove(origin, destination)) && !caseIsOccupiedSameColor(origin, destination) && isPathClear(origin,destination);
        }
        else if (isBishop(findPiece(origin).get()))
        {
            return isDiagonalMove(origin, destination) && !caseIsOccupiedSameColor(origin, destination) && isPathClear(origin,destination);
        }
    if (isKnight(findPiece(origin).get()))
    {
        return isKnightMove(origin, destination) && !caseIsOccupiedSameColor(origin, destination);
    }
    else if (isPawn(findPiece(origin).get()))
    {
        if (beginning) {
            if (caseIsOccupied(destination))
            {
                if(findPiece(origin)->getColor()==Piece::Color::BLACK){
                    return isDiagonalMove(origin, destination) && (moveStep(origin, destination) == 1) && !caseIsOccupiedSameColor(origin, destination)
                        && origin.second>=destination.second;
                }
                else{
                    return isDiagonalMove(origin, destination) && (moveStep(origin, destination) == 1) && !caseIsOccupiedSameColor(origin, destination)
                        && origin.second<=destination.second;
                }
            }
            if(findPiece(origin)->getColor()==Piece::Color::BLACK){
                return isVerticalMove(origin, destination) && ((moveStep(origin, destination) == 2 || moveStep(origin, destination) == 1))
                        && !caseIsOccupiedSameColor(origin, destination) && origin.second>=destination.second;
            }
           else{
                 return isVerticalMove(origin, destination) && ((moveStep(origin, destination) == 2 || moveStep(origin, destination) == 1))
                         && !caseIsOccupiedSameColor(origin, destination) &&  origin.second<=destination.second;
            }
        }
        else {
            if (caseIsOccupied(destination))
            {
                if(findPiece(origin)->getColor()==Piece::Color::BLACK){
                    return isDiagonalMove(origin, destination) && (moveStep(origin, destination) == 1) && !caseIsOccupiedSameColor(origin, destination)
                        && origin.second>=destination.second;
                }
                else{
                    return isDiagonalMove(origin, destination) && (moveStep(origin, destination) == 1) && !caseIsOccupiedSameColor(origin, destination)
                        && origin.second<=destination.second;
                }
            }
            else
            {
                 if(findPiece(origin)->getColor()==Piece::Color::BLACK){
                    return isVerticalMove(origin, destination) && (moveStep(origin, destination) == 1) && !caseIsOccupiedSameColor(origin, destination)
                        && origin.second>=destination.second;
                 }
                 else{
                     return isVerticalMove(origin, destination) && (moveStep(origin, destination) == 1) && !caseIsOccupiedSameColor(origin, destination)
                        && origin.second<=destination.second;
                 }
            }
        }
    }
    return false;
}

int ChessBoard::charToInt(char coord) const {
    return map.find(coord)->second-1;
}

// TODO a la place de prendre pieceTomoe ca doit prendre une pair int int
bool ChessBoard::caseIsOccupiedSameColor(std::pair<int,int> origin, std::pair<int, int> destination) {
    auto piece = findPiece(std::make_pair(destination.first, destination.second));
    if (piece!=nullptr && findPiece(origin)->getColor()==piece->getColor())
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

void ChessBoard::addPiece(std::shared_ptr<Piece> piece) {
    this->pieces_.push_back(piece);
}
// TODO a la place de prendre pieceTomoe ca doit prendre une pair int int
bool ChessBoard::isPathClear(std::pair<int, int> origin, std::pair<int, int> toCoords)
{
    using namespace pieceMovements;
       // Gather some information about the move
       int moveLength = moveStep(origin, toCoords);
       bool isVertical = isVerticalMove(origin, toCoords);
       bool isHorizontal = isHorizontalMove(origin, toCoords);
       bool isDiagonal = isDiagonalMove(origin, toCoords);
       bool movingSouth = origin.second >  toCoords.second; 			// "south" meaning from black side to white side
       bool movingEast = origin.first> toCoords.first;			// "east" meaning from white left to white right

       // If same or adjacent location, then path is definitely clear
       if (moveLength == 0 || moveLength == 1)
       {
           return true;
       }

       // Check intermediate locations between fromCoords and toCoords for vacancy
       std::pair<int, int> fromTemp = origin;
       std::pair<int, int> toTemp = toCoords;
       if (isVertical)
       {
           // We can halve the number of for-loops if we swap the start and end points depending on the direction of travel
           if (!movingSouth)
           {
               std::swap(fromTemp, toTemp);
           }

           for (int i = fromTemp.second - 1; i > toTemp.second; i--)
           {
               if (caseIsOccupied(std::make_pair( fromTemp.first,i)))
               {
                   return false;
               }
           }

           // Checked all intermediate locations and found them to be empty, so can return true
           return true;
       }
       else if (isHorizontal)
       {
           // We can halve the number of for-loops if we swap the start and end points depending on the direction of travel
           if (!movingEast)
           {
               std::swap(fromTemp, toTemp);
           }

           for (int i = fromTemp.first - 1; i > toTemp.first; i--)
           {
               if (caseIsOccupied(std::make_pair(i, fromTemp.second)))
               {
                   return false;
               }
           }

           // Checked all intermediate locations and found them to be empty, so can return true
           return true;
       }
       else if (isDiagonal)
       {
           if (movingSouth == movingEast) 			// moving southeast or northwest
           {
               // loop assumes southeast travel, swap if that's not the case
               if (!movingSouth && !movingEast)
               {
                   std::swap(fromTemp, toTemp);
               }

               int col = fromTemp.first - 1;
               for (int row = fromTemp.second - 1; row > toTemp.second; row--)
               {
                   if (caseIsOccupied(std::make_pair(col, row)))
                   {
                       return false;
                   }
                   col--;
               }

               // Checked all intermediate locations and found them to be empty, so can return true
               return true;

           }
           else if (movingSouth != movingEast)		// moving northeast or southwest
           {
               // loop assumes northeast travel, swap if that's not the case
               if (movingSouth && !movingEast)
               {
                   std::swap(fromTemp, toTemp);
               }

               int col = fromTemp.first - 1;
               for (int row = fromTemp.second + 1; row < toTemp.second; row++)
               {
                   if (caseIsOccupied(std::make_pair(col , row)))
                   {
                       return false;
                   }
                   col--;
               }

               // Checked all intermediate locations and found them to be empty, so can return true
               return true;
           }
       }

       // path is neither vertical, horizontal, nor diagonal, so it's not a clear path
       return false;
   }
std::pair<int, int> ChessBoard::getKingLocation(Piece::Color color) {
    using namespace isPiece;
    for (auto&& elem: pieces_) {
        if (isKing(elem.get()) && Piece::Color(elem->getColor()) == color) {
            return elem->getPosition();
        }
    }
    //The  function will never be used if no king is found return 0,0 to avoid compiler warnings
    return std::make_pair(0,0);
}

std::vector<std::pair<int, int>> ChessBoard::getPiecesLocation(Piece::Color color) {
    std::vector<std::pair<int, int>> locations;
    for (auto&& elem : pieces_) {
        if (Piece::Color(elem->getColor()) == color) {
            locations.push_back(elem->getPosition());
        }
    }
    return locations;
}

std::vector<std::pair<int, int>> ChessBoard::getLocations() {
    std::vector<std::pair<int, int>> locations;
    for (auto&& elem : pieces_) {
        locations.push_back(elem->getPosition());
    }
    return locations;
}

void ChessBoard::move(std::pair<int, int> origin,std::pair<int, int> destination){
    auto piece= findPiece(origin);
    auto attackedPiece = findPiece(destination);
    piece->move(destination);
    if(attackedPiece!=nullptr){
         capturePiece(attackedPiece);
    }
}

void ChessBoard::revertMove(std::pair<int, int> previous, std::shared_ptr<Piece> piece){
    piece->setPosition(piece->getPreviousPosition());
    piece->setPreviousPosition(previous);
}

//void ChessBoard::clear(){
 //   boardInit();
 //   capturedPieces_.clear();
 //   pieces_.clear();
//}
