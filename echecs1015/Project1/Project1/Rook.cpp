#include "Rook.h"
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

Rook::Rook() {

	symbol = 'T';
}
bool Rook::validMove() {
	int x = position.first;
	int y = position.second;
	int pas = abs(position.first - previousPosition.first);
	std::vector<pair<int, int>> mouvementsAutorises{ { x, y - pas }, { x , y + pas }, { x - pas, y }, { x + pas, y } };
	if (find(mouvementsAutorises.begin(), mouvementsAutorises.end(), position) != mouvementsAutorises.end()) {
		return true;
	}
	position = previousPosition;
	return false;

};

void Rook::move(char x, int y) {
	previousPosition = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;
};
