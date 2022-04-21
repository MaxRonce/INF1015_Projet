#include "Echiquier.h"
#include "Roi.h"
#include "Reine.h"
#include "Tour.h"
#include <iostream>
using namespace std;

Echiquier::Echiquier() {
	char board2[8][8] = {
		//  H    G    F    E    D    C    B    A 
		 { '0', '0', '0', '0', '0', '0', '0', '0',},//1
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//2
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//3
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//4
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//5
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//6
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//7
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//8
	};

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			board[i][j] = board2[i][j];
		}
	}

		Roi roiA;
		pieces.push_back(make_shared<Roi>(roiA));
		Roi roiB;
		pieces.push_back(make_shared<Roi>(roiB));
		Reine reineA;
		pieces.push_back(make_shared<Reine>(reineA));
		Reine reineB;
		pieces.push_back(make_shared<Reine>(reineB));
		Tour tourAA;
		pieces.push_back(make_shared<Tour>(tourAA));
		Tour tourAB;
		pieces.push_back(make_shared<Tour>(tourAB));
		Tour tourBA;
		pieces.push_back(make_shared<Tour>(tourBA));
		Tour tourBB;
		pieces.push_back(make_shared<Tour>(tourBB));
		initialisation();

};

void Echiquier::initialisation() {
	pieces[0]->deplacer('E', 1);
	pieces[0]->setPositionPrecedente();
	pieces[1]->deplacer('E', 8);
	pieces[1]->setPositionPrecedente();
	pieces[2]->deplacer('D', 1);
	pieces[2]->setPositionPrecedente();
	pieces[3]->deplacer('D', 8);
	pieces[3]->setPositionPrecedente();
	pieces[4]->deplacer('H', 1);
	pieces[4]->setPositionPrecedente();
	pieces[5]->deplacer('A', 1);
	pieces[5]->setPositionPrecedente();
	pieces[6]->deplacer('H', 8);
	pieces[6]->setPositionPrecedente();
	pieces[7]->deplacer('A', 8);
	pieces[7]->setPositionPrecedente();
}
void Echiquier::afficher() {
	synchroniserBoard();
	std::cout << "  H G F E D C B A \n";
	for (int i = 0; i < 8; ++i) {
		std::cout << i + 1 << "|";
		for (int j = 0; j < 8; ++j) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
};

void Echiquier::modifierBoard(const Piece& piece) {
	board[piece.getPositionPrecedente().second - 1][piece.getPositionPrecedente().first - 1] = '0';
	board[piece.getPosition().second - 1][piece.getPosition().first - 1] = piece.getSymbole();
};

void Echiquier::synchroniserBoard() {
	for (shared_ptr<Piece> i : pieces) {
		modifierBoard(*i.get());
	}
};
shared_ptr<Piece> Echiquier::trouverPiece(char x, int y) {
	for (auto&& elem : pieces) {
		if (elem->getPosition().first == elem->map.find(x)->second && elem->getPosition().second == y) {
			return elem;
		}
	}
}