#include <iostream>
#include <vector>
#include <utility>

class JeuEchec {
	int nbPiecePrise;
	std::vector<char> piecesPrises;
};

class Case {
public:
	bool occupee; //True si occupee
private:
	int x, y; //coordones

};

class Echiquier {
	char echiquier[8][8]; //[colonne] [ligne]
};


class Piece {
public:
	virtual bool mouvementValide(std::pair<int, int>& mouvement, int pas) = 0;
	virtual void deplacer(const int x, const int y) = 0;

private:

	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;
	char piece = 'P';
};

class Roi : public Piece {
public:
	Roi(int a, int b) : x_(a), y_(b) { ++compteurInstance; };
	bool mouvementValide(std::pair<int, int>& mouvement, int pas) override;
	void deplacer(const int x, const int y) override;
	~Roi() { --compteurInstance; };
private:

	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;
	char piece = '$';
	static int inline compteurInstance;

};

class Reine : public Piece {
public:
	bool mouvementValide(std::pair<int, int>& mouvement, int pas) override;
	void deplacer(const int x, const int y) override;

private:

	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;
	char piece = 'R';

};

class Tour : public Piece {
public:
	bool mouvementValide(std::pair<int, int>& mouvement, int pas) override;
	void deplacer(const int x, const int y) override;
	
private:

	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;
	char piece = 'T';

};
