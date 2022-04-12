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

void Roi::setPositionPrecedente() {
	positionPrecedente = getPosition();
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
void Reine::setPositionPrecedente() {
	positionPrecedente = getPosition();
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

void Tour::setPositionPrecedente() {
	positionPrecedente = getPosition();
};

const char Tour::getSymbole() const {
	return symbole;
};

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

};

void Echiquier::initialisation(){
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
	board[piece.getPositionPrecedente().second - 1][piece.getPositionPrecedente().first - 1] ='0';
	board[piece.getPosition().second - 1][piece.getPosition().first - 1] = piece.getSymbole();
};

void Echiquier::synchroniserBoard() {
	for(shared_ptr<Piece> i : pieces){
		modifierBoard(*i.get());
	}
};
