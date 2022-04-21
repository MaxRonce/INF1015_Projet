#include "Echiquier.h"
#include "Roi.h"
#include "Reine.h"
#include "Tour.h"
#include "Piece.h"
#include "InstancesRoiException.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

shared_ptr<Piece> choisirPiece(Echiquier echiquier);
void deplacement(shared_ptr<Piece> piece);

int main() {
	Echiquier echiquier;
	try {
		cout << "Welcome Player, To Chess Game\n";
		while (true) {
			echiquier.afficher();
			auto piece = choisirPiece(echiquier);
			deplacement(piece);
			system("CLS");
		}
	}
	catch (InstancesRoiException& except) {
		cout << "Execution Error : " << except.what() << endl;
	}
}

shared_ptr<Piece> choisirPiece(Echiquier echiquier) {
	char x = 0;
	int y = 0;
	cout << "\nPlease Choose Piece To Move :\n";
	cin >> x >> y;
	auto piece = echiquier.trouverPiece(x, y);
	while (piece == nullptr) {
		cout << "\nInvalid Piece, Please Insert Valid Move : \n";
		cin >> x >> y;
		piece = echiquier.trouverPiece(x, y);
	}
	return piece;
}
void deplacement(shared_ptr<Piece> piece) {
	char x = 0;
	int y = 0;
	cout << "\nYour Next Move : \n";
	cin >> x >> y;
	piece->deplacer(x, y);
	while (!piece->mouvementValide()) {
		cout << "\nInvalid Move, Please Insert Valid Move : \n";
		cin >> x >> y;
		piece->deplacer(x, y);
	}
}