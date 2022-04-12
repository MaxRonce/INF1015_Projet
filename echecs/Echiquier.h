#include "Piece.h"
#include <vector>
#include <memory>

class Echiquier {
public:
	Echiquier();
	void initialisation();
	void modifierBoard(const Piece& piece);
	void synchroniserBoard();
	void afficher();
	std::vector<std::shared_ptr<Piece>> pieces;

private:
	char board[8][8] = {}; //[colonne] [ligne]

};