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
private:
	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;
};

class Roi : public Piece {
public:
	Roi(int a, int b) : x_(a), y_(b) {};
	bool mouvementValide(std::pair<int, int>& mouvement, int pas) override;

	/*  void avancer();
	  void reculer();
	  void avancerDroite();
	  void avancerGauche();
	  void diagonaleDroite();
	  void diagonaleGauche();
	  void diagonaleHaut();
	  void diagonaleBas();*/
private:

	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;

};

class Reine : public Piece {
public:
	bool mouvementValide(std::pair<int, int>& mouvement, int pas) override;
	/*  void avancer(const int x, const int y);
	  void reculer(const int x, const int y);
	  void avancerDroite(const int x, const int y);
	  void avancerGauche(const int x, const int y);
	  void diagonaleDroite(const int x, const int y);
	  void diagonaleGauche(const int x, const int y);
	  void diagonaleHaut(const int x, const int y);
	  void diagonaleBas(const int x, const int y);*/

private:

	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;

};

class Tour : public Piece {
public:
	bool mouvementValide(std::pair<int, int>& mouvement, int pas) override;
	/*  void avancer();
	  void reculer();
	  void avancerDroite();
	  void avancerGauche ();*/

private:

	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> mouvement_;

};
