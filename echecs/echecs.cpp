#include "echecs.h"
#include <algorithm>
using namespace std;

Roi::Roi(int a, int b) : x_(a), y_(b)
{
	++compteurInstance;
	if (compteurInstance > 2)
		throw InstancesRoiException("PLus que 2 instances de Roi"); //Oublie pas de mettre le try catch dans le main
};

Roi::~Roi() { --compteurInstance; };

bool Roi::mouvementValide(pair<int, int>& mouvement, int pas) {

	std::vector<pair<int, int>> mouvementsAutorises{ {x_ , y_ - pas }, {x_ , y_ + pas }, {x_ - pas, y_}, {x_ + pas, y_ }, {x_ - pas, y_ - pas }, {x_ + pas, y_ + pas }, {x_ - pas, y_ + pas}, {x_ + pas, y_ - pas } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), mouvement) != mouvementsAutorises.end()) {
		return true;
	}
	else {
		if (*mouvementsAutorises.end() == mouvement) {
			return true;
		}
		return false;
	}

};

void Roi::deplacer(const int x, const int y) {
	mouvement_.first+=x;
	mouvement_.second+=y;

}

bool Reine::mouvementValide(pair<int, int>& mouvement, int pas) {

	return true;

};

void Reine::deplacer(const int x, const int y) {
	mouvement_.first += x;
	mouvement_.second += y;
}

bool Tour::mouvementValide(pair<int, int>& mouvement, int pas) {

	std::vector<pair<int, int>> mouvementsAutorises{ { x_ , y_ - pas }, { x_ , y_ + pas }, { x_ - pas, y_ }, { x_ + pas, y_ } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), mouvement) != mouvementsAutorises.end()) {
		return true;
	}
	else {
		if (*mouvementsAutorises.end() == mouvement) {
			return true;
		}
		return false;
	}

};

void Tour::deplacer(const int x, const int y) {
	mouvement_.first += x;
	mouvement_.second += y;
}