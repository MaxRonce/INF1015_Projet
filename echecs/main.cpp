#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Piece.h"
#include "InstancesKingException.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

shared_ptr<Piece> choisirPiece(ChessBoard ChessBoard);
void deplacement(shared_ptr<Piece> piece);

int main() {
	ChessBoard ChessBoard;
	try {
		cout << "Welcome Player, To Chess Game\n";
		while (true) {
			ChessBoard.show();
			auto piece = choisirPiece(ChessBoard);
			deplacement(piece);
			system("CLS");
		}
	}
	catch (InstancesKingException& except) {
		cout << "Execution Error : " << except.what() << endl;
	}
}

shared_ptr<Piece> choisirPiece(ChessBoard ChessBoard) {
	char x = 0;
	int y = 0;
	cout << "\nPlease Choose Piece To Move :\n";
	cin >> x >> y;
	auto piece = ChessBoard.findPiece(x, y);
	while (piece == nullptr) {
		cout << "\nInvalid Piece, Please Insert Valid Move : \n";
		cin >> x >> y;
		piece = ChessBoard.findPiece(x, y);
	}
	return piece;
}

void deplacement(shared_ptr<Piece> piece) {
	char x = 0;
	int y = 0;
	cout << "\nYour Next Move : \n";
	cin >> x >> y;
	piece->move(x, y);
	while (!piece->validMove()) {
		cout << "\nInvalid Move, Please Insert Valid Move : \n";
		cin >> x >> y;
		piece->move(x, y);
	}
}