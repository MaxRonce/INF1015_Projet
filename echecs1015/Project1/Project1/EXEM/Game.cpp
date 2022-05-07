/*
* TP6 INF1015
* \file   Game.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*/
#pragma once
#include "Game.h"
#include "Piece.h"
#include "ChessBoard.h"
#include <iostream>
#include <QDebug>
#include <string>

	namespace coordination {
		std::pair<int, int> destionationCoord(ChessBoard* chessBoard, char x, int y) {
			std::shared_ptr<Piece> attackedPiece = chessBoard->findPiece(std::make_pair(chessBoard->charToInt(x), y)); ;
			if (attackedPiece != nullptr)
			{
				return  { attackedPiece->getPosition().first, attackedPiece->getPosition().second };
			}
			else
			{
				return { chessBoard->charToInt(x), y };
			}
		}
	}
		namespace test {
			bool pieceIsKing(Piece* piece) {
				auto ptr = dynamic_cast<King*>(piece);
				if (ptr != nullptr)
				{

					return true;

				}
				return false;

			}
		}
 void Game::defaultMode(){
     resetMoves();
     guiTurn = Piece::Color::WHITE;
     board_->defaultChess();
 }

//void Game::restart(){
//    guiTurn = Piece::Color::WHITE;
//    end_=false;
//    resetMoves();
//    board_->clear();
//}

	bool Game::isInCheck(Piece::Color defendingColor) const
	{
		Piece::Color attackingColor;
		if (defendingColor == Piece::Color::WHITE)
		{
			attackingColor = Piece::Color::BLACK;
		}
		else
		{
			attackingColor = Piece::Color::WHITE;
		}
		std::pair<int, int> kingLocation = board_->getKingLocation(defendingColor);
		std::vector<std::pair<int, int>> pieceLocations = board_->getPiecesLocation(attackingColor);
        for ( auto piece : pieceLocations)
		{
            if (board_->isValidMove(piece, kingLocation))
			{
				return true;
			}
		}

		return false;
	}


	bool Game::isInCheckMate(Piece::Color defendingColor)
	{
		if (isInCheck(defendingColor))
		{
			std::vector<std::pair<int, int>> pieceLocations = board_->getPiecesLocation(defendingColor);
			std::vector<std::pair<int, int>> locations = board_->getLocations();

            for (auto const& pieceLocation : pieceLocations)
			{
                for (auto const& location : locations)
				{	
                    if (board_->isValidMove(pieceLocation, location))
					{
                        auto tempPrevPos = board_->findPiece(pieceLocation)->getPreviousPosition();
                        auto piece = board_->findPiece(pieceLocation);
                       board_->findPiece(pieceLocation)->move(location);
						// If player is no longer in check, then there's hope
						if (!isInCheck(defendingColor))
						{
                            board_->revertMove(tempPrevPos,piece);
							return false;
						}
                        board_->revertMove(tempPrevPos,piece);

					}
				}
			}
		}
		else
		{
			return false;
		}

		return true;
	}

	/*The conditions of stalemate are:
	 * - Not in check
	 * - No legal moves */
	bool Game::isInStalemate(Piece::Color defendingColor)
	{
		if (isInCheck(defendingColor))
		{
			return false;
		}
		else
		{
			std::vector<std::pair<int, int>> pieceLocations = board_->getPiecesLocation(defendingColor);
			std::vector<std::pair<int, int>> locations = board_->getLocations();

			for (auto const& pieceLocation : pieceLocations)
			{
				for (auto const& location : locations)
				{
					if (board_->isValidMove(pieceLocation, location))
					{
                        auto tempPrevPos = board_->findPiece(pieceLocation)->getPreviousPosition();
                        auto piece= board_->findPiece(pieceLocation);
                        board_->findPiece(pieceLocation)->move(location);
						if (!isInCheck(defendingColor))
						{
                            board_->revertMove(tempPrevPos,piece);
							return false; 
						}
                        board_->revertMove(tempPrevPos,piece);
					}
				}
			}
		}
        return true;
	}


	/*  Castling requires:
	 * - Neither the king nor the chosen rook has previously moved.
	 * - There are no pieces between the king and the chosen rook.
	 * - The king is not currently in check. */
	bool Game::castle(const Piece::Color toMove, const std::pair<int, int> origin, const std::pair<int, int> destination)
	{
		
		std::pair<int, int> rooksNext;
		std::pair<int, int> rookLocation;
        if (destination == std::make_pair (board_->charToInt('G'), 7))
		{
            rookLocation = std::make_pair(board_->charToInt('H'), 7);
            rooksNext = std::make_pair(board_->charToInt('F'), 7);
		}
        else if (destination == std::make_pair(board_->charToInt('C'), 7))
		{
            rookLocation = std::make_pair(board_->charToInt('A'), 7);
            rooksNext = std::make_pair(board_->charToInt('D'), 7);
		}
        else if (destination == std::make_pair(board_->charToInt('G'), 0))
		{
            rookLocation = std::make_pair(board_->charToInt('H'), 0);
            rooksNext = std::make_pair(board_->charToInt('F'), 0);
		}
        else if (destination == std::make_pair(board_->charToInt('C'), 0))
		{
            rookLocation = std::make_pair(board_->charToInt('A'), 0);
            rooksNext = std::make_pair(board_->charToInt('D'), 0);
		}
		else
		{
			return false;
		}

		auto rook = board_->findPiece(rookLocation);

        if (!board_->isPathClear(origin, rookLocation))
        {
            return false;
        }
        if (isInCheck(toMove))
        {
            return false;
        }
		auto king = board_->findPiece(origin);
		
        if (!king->firstMove() || !rook->firstMove())
        {
            return false;
        }
        rook->move(rooksNext);
		return true;
	}


	/* Determine whose turn it is based on the number of moves in the current game. */
	Piece::Color Game::getTurn(int moveNumber) const
	{
		if (moveNumber % 2 == 1)
		{
			return Piece::Color::WHITE;
		}
		else
		{
			return Piece::Color::BLACK;
		}
	}

	/* Print the string representation of a Color enum. */
	std::string Game::printColor(Piece::Color color)
	{
		if (color == Piece::Color::WHITE)
		{
			return "White";
		}
		else
		{
			return "Black";
		}
	}

	// Change guiTurn between White/Black
	void Game::switchGuiTurn()
	{
		if (guiTurn == Piece::Color::WHITE)
		{
			guiTurn = Piece::Color::BLACK;
		}
		else {
			guiTurn = Piece::Color::WHITE;
		}
         emit colorChange();
	}


	// Clear move1 and move2 strings
	void Game::resetMoves()
	{
		move1 = "";
		move2 = "";
	}



   void Game::getInput(QString input)
   {
       qDebug() << "Game saw that " << input << "was clicked, and will now respond.";

       // If this is the first click, store it in move1
       if (move1 == "")
       {
           move1 = input.toStdString();
       }
       // If this is the second click, store it in move2
       else
       {
           move2 = input.toStdString();
           // We can now pass the move to the Game
           std::pair<int, int> origin = inputToPos(move1); 	// convert substring to pair
           std::pair<int, int> destination = inputToPos(move2);		// convert substring to pair
           // Verify that a piece was selected
           // qDebug() << "move 1 " << QString::fromStdString(std::to_string(origin.first))<< " " <<QString::fromStdString(std::to_string(origin.second));
            //qDebug() << "move 2 " << QString::fromStdString(std::to_string(destination.first))<< " " <<QString::fromStdString(std::to_string(destination.second));
           if (board_->findPiece(origin) == nullptr)
           {
               qDebug() << "No piece selected.";
               emit sendResponse("Invalid Move");
               resetMoves();
               return;
           }
           if (Piece::Color(board_->findPiece(origin)->getColor()) != guiTurn)
           {
               qDebug() << "Game.cpp: Error: Not your turn.";
               emit sendResponse("Invalid Move");
               resetMoves();
               return;
           }

           // Check if this is an attempted castle and handle accordingly
           if (test::pieceIsKing(board_->findPiece(origin).get()) && board_->moveStep(origin, destination) > 1 )
           {
               if (castle(guiTurn, origin, destination))
               {
                   switchGuiTurn();
                   qDebug() << "Castled!";
                   // Signal the Display to change the images appropriately
                   // If it is the White King...
                   if (origin.second == 0)
                   {
                       // If Kingside...
                       if (destination.first == 1)
                       {
                           emit sendResponse("Castle White Kingside");
                       }
                       else
                       {
                           emit sendResponse("Castle White Queenside");
                       }
                   }
                   // else if it is the Black King...
                   else if (origin.second == 7)
                   {
                       if (destination.first == 1)
                       {
                           emit sendResponse("Castle Black Kingside");
                       }
                       else
                       {
                           emit sendResponse("Castle Black Queenside");
                       }
                   }
               }
               else
               {   
                  qDebug() << "Invalid Move";
               }
           }

           // Attempt to move piece
           else if (board_->isValidMove(origin,destination))
           {
               auto tempPrevPos = board_->findPiece(origin)->getPreviousPosition();
               auto piece =  board_->findPiece(origin);
               // qDebug() << "tempPrevPos"<< QString::fromStdString(std::to_string(tempPrevPos.first))<<" "<<QString::fromStdString(std::to_string(tempPrevPos.second));
               (board_->findPiece(origin))->move(destination);
               // Verify that move doesn't put player in check, else switch players
              if (isInCheck(guiTurn))
               {
                   // If move puts player in check, print error, revert move, and let player enter different move
                   board_->revertMove(tempPrevPos,board_->findPiece(destination));
                   qDebug() << "Error: This leaves you in check.";
                   emit sendResponse("Check, Invalid Move");
               }
               // If the move was valid, switch turns and send "Valid" response
               else
               {
                  // qDebug() << "revertMove"<< QString::fromStdString(std::to_string(board_->findPiece(destination)->getPosition().first))<<" "<<QString::fromStdString(std::to_string(board_->findPiece(destination)->getPosition().second));
                   board_->revertMove(tempPrevPos,piece);
                  //  qDebug() << " after Revert"<< QString::fromStdString(std::to_string(piece->getPosition().first))<<" "<<QString::fromStdString(std::to_string(piece->getPosition().second));
                   board_->move(origin,destination);
                   switchGuiTurn();

                   // Send QString response containing the two spaces of the valid move
                   QString sendStr = "";
                   QString part1 = QString::fromStdString(move1);
                   QString part2 = QString::fromStdString(move2);
                   sendStr += part1;
                   sendStr += part2;
                   emit sendResponse(sendStr);
               }
           }
           else
           {
               std::cout << "Error: Invalid move.\n";
               qDebug() << "Error: Invalid move.";
              emit  sendResponse("Invalid Move");
           }

           if (isInCheckMate(guiTurn) == true)
           {
              end_=true;
              emit sendResponse("Checkmate");
           }
           else if (isInCheck(guiTurn) == true)
            {
              emit sendResponse("Check");
            }
           else if (isInStalemate(guiTurn))
           {
              emit sendResponse("Stalemate");
           }

           resetMoves();
       }

   }

	std::pair<int, int> Game::inputToPos(std::string coords) const
	{
        int row = coords[0] - 'a'; 			// shift ascii letter to integer
        int col = 8-(coords[1] - '0');			// shift ascii letter to integer and flip
        return std::make_pair(row, abs(7-col));
	}
