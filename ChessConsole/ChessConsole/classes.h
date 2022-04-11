#include <vector>
#include <string.h>
class Case {
public : 
	bool occupee; //True si occupee
	int x,y; //coordones

};

class Echiquer {
public:
	char board[8][8]; //[colonne] [ligne]

	Echiquer() {
		char board[8][8] = {
		//base settings
		//  H    G    F    E    D    C    B    A 
		 { 'T', 'B', '0', '0', 'K', '0', 'B', 'T',},//1
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//2
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//3
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//4
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//5
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//6
		 { '0', '0', '0', '0', '0', '0', '0', '0' },//7
		 { 'T', 'B', '0', '0', 'K', '0', 'B', 'T' },//8
	};
		
	}
	void afficher() {
		std::cout << "  H G F E D C B A \n";
		for (int i = 0; i < 8; ++i) {
			std::cout << i+1 << "|";
			for (int j = 0; j < 8; ++j) {
				std::cout << board[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
};

class JeuEchec {
	int nbPiecePrise;
	std::vector<char> piecesPrises;
};

class Piece {
public:
	int x, y;
	virtual bool mouvementValide(const int x, const int y) = 0 ;
	virtual void deplacement() = 0;
};

class Roi : public Piece {
public:

};

class Fou : public Piece {
public:
};