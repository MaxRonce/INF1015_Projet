#include "echecs.h"
#include <algorithm>
using namespace std;


Roi::Roi()
{
	++compteurInstance;
	if (compteurInstance > 2)
		throw InstancesRoiException("Plus que 2 instances de Roi"); 
};

Roi::~Roi() { --compteurInstance; };

bool Roi::mouvementValide(int pas) {

	std::vector<pair<int, int>> mouvementsAutorises{ {x_ , y_ - pas }, {x_ , y_ + pas }, {x_ - pas, y_}, {x_ + pas, y_ }, {x_ - pas, y_ - pas }, {x_ + pas, y_ + pas }, {x_ - pas, y_ + pas}, {x_ + pas, y_ - pas } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	else {
		if (*mouvementsAutorises.end() == position) {
			return true;
		}
		return false;
	}

};

void Roi::deplacer(char x, int y) {
	positionPrecedente = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;

};

const std::pair<int, int> Roi::getPosition() const {
	return position;
};
const std::pair<int, int> Roi::getPositionPrecedente() const {
	return this->positionPrecedente;
};

const char Roi::getSymbole() const {
	return symbole;
};

bool Reine::mouvementValide(int pas) {

	return true;

};

void Reine::deplacer(char x, int y) {
	positionPrecedente = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;
};

const std::pair<int, int> Reine::getPosition() const {
	return position;
};

const std::pair<int, int> Reine::getPositionPrecedente() const {
	return this->positionPrecedente;
};

const char Reine::getSymbole() const {
	return symbole;
};

bool Tour::mouvementValide(int pas) {

	std::vector<pair<int, int>> mouvementsAutorises{ { x_ , y_ - pas }, { x_ , y_ + pas }, { x_ - pas, y_ }, { x_ + pas, y_ } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	else {
		if (*mouvementsAutorises.end() == position) {
			return true;
		}
		return false;
	}

};

void Tour::deplacer(char x, int y) {
	positionPrecedente = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;
};

const std::pair<int, int> Tour::getPosition() const {
	return position;
};

const std::pair<int, int> Tour::getPositionPrecedente() const {
	return this->positionPrecedente;
};

const char Tour::getSymbole() const {
	return symbole;
};

Echiquier::Echiquier() {
	char board2[8][8] = {
		//  H    G    F    E    D    C    B    A 
		 { 'T', '0', '0', 'K', 'Q', '0', '0', 'T',},//1
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//2
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//3
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//4
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//5
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//6
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//7
		 { 'T', '0', '0', 'K', 'Q', '0', '0', 'T' },//8
	};

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			board[i][j] = board2[i][j];
		}
	}
	roiA.deplacer( 'E', 1 );
	roiB.deplacer( 'E', 8 );
	reineA.deplacer('D', 1 );
	reineB.deplacer( 'D', 8 );
	tourAA.deplacer( 'H', 1 );
	tourAB.deplacer( 'A', 1 );
	tourBA.deplacer( 'H', 8 );
	tourBB.deplacer( 'A', 8 );

};

void Echiquier::modifierBoard(const Piece& piece) {
	board[piece.getPositionPrecedente().second - 1][piece.getPositionPrecedente().first - 1] ='0';
	board[piece.getPosition().second - 1][piece.getPosition().first - 1] = piece.getSymbole();
};

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


void Echiquier::synchroniserBoard() {
	modifierBoard(reineA);
	/*modifierBoard(reineB.position.first, reineB.position.second, reineB.symbole);
	modifierBoard(roiA.position.first, roiA.position.second, roiA.symbole);
	modifierBoard(roiB.position.first, roiB.position.second, roiB.symbole);
	modifierBoard(tourAA.position.first, tourAA.position.second, tourAA.symbole);
	modifierBoard(tourAB.position.first, tourAB.position.second, tourAB.symbole);
	modifierBoard(tourBA.position.first, tourBA.position.second, tourBA.symbole);
	modifierBoard(tourBB.position.first, tourBB.position.second, tourBB.symbole);*/
};