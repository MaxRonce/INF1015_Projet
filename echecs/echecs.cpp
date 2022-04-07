#include "echecs.h"
#include <algorithm>
using namespace std;

bool Roi::mouvementValide(pair<int, int>& mouvement, int pas) {

	std::vector<pair<int, int>> mouvementsAutorises{ {x_ , y_ - pas }, {x_ , y_ + pas }, {x_ - pas, y_}, {x_ + pas, y_ }, {x_ - pas, y_ - pas }, {x_ + pas, y_ + pas }, {x_ - pas, y_+pas}, {x_ + pas, y_-pas } };

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

bool Reine::mouvementValide(pair<int, int>& mouvement, int pas) {



};

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