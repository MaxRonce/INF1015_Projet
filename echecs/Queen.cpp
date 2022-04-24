#include "Queen.h"
#include <iostream>
#include <utility>

using namespace std;

Queen::Queen() {
	
	symbol= 'Q';
}
bool Queen::validMove() {
	if (position.first) {
		return false;
	}
	return true;

};

void Queen::move(char x, int y) {
	previousPosition = position;
	auto coordonnees = map.find(x);
	position.first = coordonnees->second;
	position.second = y;
};

