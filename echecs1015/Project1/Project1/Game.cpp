/*
* TP6 INF1015
* \file   Game.cpp
* \author Nada Alami Chentoufi et Maxime Ronceray
* \date   25 avril 2022
* Créé le 20 avril 2022
*
*/
#pragma once
#include "Game.h"
#include <iostream>
#include <stdlib.h>


Game::Game():
board_(new ChessBoard){
}

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
	void Game::start() {
		using namespace test;
		using namespace coordination;
		std::pair<int, int> destination;
		char x = 0;
		int y = 0;
		//Turns
		int currentMove = 1;
		Piece::Color toMove = getTurn(currentMove);
		std::cout << "Welcome Player, To Chess Game\n";
		std::cout << "Please Insert Y Movement Then X Movement\n";
		std::cout << "Example : A2\n";
		std::cout << "Happy Game :)!\n";
		try {
			while (!end_) {
				if (isInCheckMate(toMove)) {
					std::cout << printColor(toMove) << " is in checkmate. Game over." << '\n';
					break;
				}
				if (isInStalemate(toMove))
				{
					std::cout << printColor(toMove) << " is in stalemate. Draw." << '\n';
					break;
				}
				board_->show();
				std::cout << printColor(toMove) << "'s turn. Enter piece to move: ";
				//Choose Piece

				std::cin >> x >> y;
				//to exit
				if (x == 'X')
				{
					end_ = true;
					break;
				}
				auto piece = board_->findPiece(std::make_pair(board_->charToInt(x), y));
				while (piece == nullptr)
				{
					std::cout << "Error: No piece at this position" << '\n';
					continue;
				}
				if (piece->getColor() != toMove)
				{
					std::cout << "Error: It's " << printColor(toMove) << "'s turn." << '\n';
					continue;
				}
				std::cout << "Enter move : ";
				std::cin >> x >> y;
				auto attackedPiece = board_->findPiece(std::make_pair(board_->charToInt(x), y));
				destination = destionationCoord(board_, x, y);

				if (pieceIsKing(piece.get())  && board_->moveStep(std::make_pair(board_->charToInt(x), y), destination) > 1)
				{
					if (castle(toMove, piece->getPosition(), destination))
					{
						currentMove++;
						toMove = getTurn(currentMove);
					}
					else
					{
						std::cout << "Error: This is an invalid castle." << '\n';
					}
					continue;
				}
				if (!board_->isValidMove(std::make_pair(board_->charToInt(x), y), destination))
				{
					std::cout << "Error: Invalid move.\n";
					continue;
				}
				if (isInCheck(toMove))
				{
					// If move puts player in check, print error, revert move, and let player enter different move
					std::cout << "Error: This leaves " << printColor(toMove) << " in check.\n";
					continue;
				}
				else
				{
					board_->capturePiece(attackedPiece);
					piece->move(std::make_pair(board_->charToInt(x), y));
					currentMove++;
					toMove = getTurn(currentMove);
				}
			}
		}
			catch (InstancesKingException& except) {
				std::cout << "Execution Error : " << except.what() << std::endl;
			}
		
	}


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
		//TO DO : add these
		std::pair<int, int> kingLocation = board_->getKingLocation(defendingColor);
		std::vector<std::pair<int, int>> pieceLocations = board_->getPiecesLocation(attackingColor);
		for ( auto destination : pieceLocations)
		{
			if (board_->isValidMove(destination, kingLocation))
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
						// If player is no longer in check, then there's hope
						if (!isInCheck(defendingColor))
						{
							
							return false;
						}

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
						if (!isInCheck(defendingColor))
						{
							return false; 
						}

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
		if (destination == std::make_pair (board_->charToInt('G'), 8))
		{
			rookLocation = std::make_pair(board_->charToInt('H'), 8);
			rooksNext = std::make_pair(board_->charToInt('F'), 8);
		}
		else if (destination == std::make_pair(board_->charToInt('C'), 8))
		{
			rookLocation = std::make_pair(board_->charToInt('A'), 8);
			rooksNext = std::make_pair(board_->charToInt('D'), 8);
		}
		else if (destination == std::make_pair(board_->charToInt('G'), 1))
		{
			rookLocation = std::make_pair(board_->charToInt('H'), 1);
			rooksNext = std::make_pair(board_->charToInt('F'), 1);
		}
		else if (destination == std::make_pair(board_->charToInt('C'), 1))
		{
			rookLocation = std::make_pair(board_->charToInt('A'), 1);
			rooksNext = std::make_pair(board_->charToInt('D'), 1);
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
	}


	// Clear move1 and move2 strings
	void Game::resetMoves()
	{
		move1 = "";
		move2 = "";
	}


	// This function is a Qt slot, a function designed to receive QObject signals.
	// It receives a signal origin the Display whenever a space is clicked. Upon collecting
	// two spaces, the move can be executed if it is valid, or ignored if not.
	//void Game::getInput(QString input)
	//{
	//	qDebug() << "Game saw that " << input << "was clicked, and will now respond.";

	//	// If this is the first click, store it in move1
	//	if (move1 == "")
	//	{
	//		move1 = input.toStdString();
	//	}
	//	// If this is the second click, store it in move2
	//	else
	//	{
	//		move2 = input.toStdString();

	//		// We can now pass the move to the Game
	//		std::pair<int, int> origin = intToPos(move1); 	// convert substring to pair
	//		std::pair<int, int> destination = intToPos(move2);		// convert substring to pair

	//		// Verify that a piece was selected
	//		if (board_->findPiece(origin) == nullptr)
	//		{
	//			qDebug() << "No piece selected.";
	//			sendResponse("Invalid Move");
	//			return;
	//		}

	//		if (board_->findPiece(origin)->getColor() != guiTurn)
	//		{
	//			std::cout << "Error: It's " << printColor(guiTurn) << "'s turn." << '\n';
	//			qDebug() << "Game.cpp: Error: Not your turn.";
	//			emit sendResponse("Invalid Move");
	//			resetMoves();
	//			return;
	//		}

	//		// Check if this is an attempted castle and handle accordingly
	//		if (isPiece::pieceIsKing(board_->findPiece(origin).get()) && board_->moveStep(origin, destination) > 1)
	//		{
	//			if (castle(guiTurn, origin, destination))
	//			{
	//				switchGuiTurn();
	//				qDebug() << "Castled!";
	//				// Signal the Display to change the images appropriately
	//				// If it is the White King...
	//				if (origin.first == 7)
	//				{
	//					// If Kingside...
	//					if (destination.second == 6)
	//					{
	//						emit sendResponse("Castle White Kingside");
	//					}
	//					else
	//					{
	//						emit sendResponse("Castle White Queenside");
	//					}
	//				}
	//				// else if it is the Black King...
	//				else if (origin.first == 0)
	//				{
	//					if (destination.second == 6)
	//					{
	//						emit sendResponse("Castle Black Kingside");
	//					}
	//					else
	//					{
	//						emit sendResponse("Castle Black Queenside");
	//					}
	//				}
	//			}
	//			else
	//			{
	//				std::cout << "Error: This is an invalid castle." << '\n';
	//				qDebug() << "Error: Invalid castle.";
	//			}
	//		}

	//		// Attempt to move piece
	//		// TODO: Check for castling here?
	//		else if (board_->findPiece(origin)->move(destination))
	//		{
	//			// Verify that move doesn't put player in check, else switch players
	//			if (isInCheck(guiTurn))
	//			{
	//				// If move puts player in check, print error, revert move, and let player enter different move
	//				std::cout << "Error: This leaves " << printColor(guiTurn) << " in check.\n";
	//				qDebug() << "Error: This leaves you in check.";
	//				sendResponse("Invalid Move");
	//			}
	//			// If the move was valid, switch turns and send "Valid" response
	//			else
	//			{
	//				switchGuiTurn();

	//				// Send QString response containing the two spaces of the valid move
	//				QString sendStr = "";
	//				QString part1 = QString::fromStdString(move1);
	//				QString part2 = QString::fromStdString(move2);
	//				sendStr += part1;
	//				sendStr += part2;
	//				sendResponse(sendStr);
	//			}
	//		}
	//		else
	//		{
	//			std::cout << "Error: Invalid move.\n";
	//			qDebug() << "Error: Invalid move.";
	//			sendResponse("Invalid Move");
	//		}

	//		if (isInCheckMate(guiTurn) == true)
	//		{
	//			sendResponse("Checkmate");
	//		}
	//		else if (isInCheck(guiTurn) == true)
	//		{
	//			sendResponse("Check");
	//		}
	//		else if (isInStalemate(guiTurn))
	//		{
	//			sendResponse("Stalemate");
	//		}

	//		resetMoves();
	//	}

	//}
	std::pair<int, int> Game::inputToPos(std::string coords) const
	{
		int col = coords[0] - 'a'; 			// shift ascii letter to integer
		int row = 8 - (coords[1] - '0');		// shift ascii letter to integer and flip
		return std::make_pair(row, col);
	}