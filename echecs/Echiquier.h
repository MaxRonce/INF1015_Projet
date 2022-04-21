#include "Piece.h"
#include <vector>
#include <memory>

class Echiquier {
public:
	Echiquier();
	void modifierBoard(const Piece& piece);
	void synchroniserBoard();
	void afficher();
	std::shared_ptr<Piece> trouverPiece(char x, int y);

private:
	std::vector<std::shared_ptr<Piece>> pieces;
	void initialisation();
	char board[8][8] = {}; //[colonne] [ligne]

};