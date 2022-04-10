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
	Roi(int a, int b);
	bool mouvementValide(std::pair<int, int>& mouvement, int pas) override;
	void deplacer(const int x, const int y) override;
	~Roi();

private:

	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;
	char piece = 'K';
	static int inline compteurInstance;

};

class InstancesRoiException : public logic_error
{
public:
	using logic_error::logic_error;
};

class Reine : public Piece {
public:
	bool mouvementValide(std::pair<int, int>& mouvement, int pas) override;
	void deplacer(const int x, const int y) override;

private:

	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;
	char piece = 'Q';

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
