#include "echecs.h"
#include <algorithm>
using namespace std;


Roi::Roi()
{
	++compteurInstance;
	if (compteurInstance > 2)
		throw InstancesRoiException("Plus que 2 instances de Roi"); //Oublie pas de mettre le try catch dans le main
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

void Roi::deplacer(pair<char, int> pair) {
	auto coordonnees = map.find(pair.first);
	position.first = coordonnees->second;
	position.second = pair.second;

};


bool Reine::mouvementValide(int pas) {

	return true;

};

void Reine::deplacer(pair<char, int> pair) {
	auto coordonnees = map.find(pair.first);
	position.first = coordonnees->second;
	position.second = pair.second;
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

void Tour::deplacer(pair<char, int> pair) {
	auto coordonnees = map.find(pair.first);
	position.first = coordonnees->second;
	position.second = pair.second;
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
	roiA.deplacer({ 'E', 1 });
	roiB.deplacer({ 'E', 8 });
	reineA.deplacer({ 'D', 1 });
	reineB.deplacer({ 'D', 8 });
	tourAA.deplacer({ 'H', 1 });
	tourAB.deplacer({ 'A', 1 });
	tourBA.deplacer({ 'H', 8 });
	tourBB.deplacer({ 'A', 8 });

};
void Echiquier::modifierBoard(int x, int y, char symbole){
	board[y][x] = symbole;
};

void Echiquier::afficher() {
	//synchroniserBoard();
	std::cout << "  H G F E D C B A \n";
	for (int i = 0; i < 8; ++i) {
		std::cout << i + 1 << "|";
		for (int j = 0; j < 8; ++j) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
};

//const shared_ptr<Roi> Echiquier::getRoiA() const {
//	shared_ptr<Roi> ptrRoi = make_shared<Roi>(roiA);
//	return ptrRoi;
//};
//
//const shared_ptr<Reine> Echiquier::getReineA() const {
//	shared_ptr<Reine> ptrReine = make_shared<Reine>(reineA);
//	return ptrReine;
//};
//
//const shared_ptr<Tour> Echiquier::getTourA() const {
//	shared_ptr<Tour> ptrRoi = make_shared<Tour>(tourAA);
//	return ptrRoi;
//};
void Echiquier::synchroniserBoard() {

	modifierBoard(reineA.position.first, reineA.position.second, reineA.symbole);
	modifierBoard(reineB.position.first, reineB.position.second, reineB.symbole);
	modifierBoard(roiA.position.first, roiA.position.second, roiA.symbole);
	modifierBoard(roiB.position.first, roiB.position.second, roiB.symbole);
	modifierBoard(tourAA.position.first, tourAA.position.second, tourAA.symbole);
	modifierBoard(tourAB.position.first, tourAB.position.second, tourAB.symbole);
	modifierBoard(tourBA.position.first, tourBA.position.second, tourBA.symbole);
	modifierBoard(tourBB.position.first, tourBB.position.second, tourBB.symbole);
};