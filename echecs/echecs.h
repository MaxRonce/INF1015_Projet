#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <map>


//class JeuEchec {
//	int nbPiecePrise;
//	std::vector<char> piecesPrises;
//};

//class Case {
//public:
//	bool occupee; //True si occupee
//private:
//	int x, y; //coordones
//
//};



class Piece {
public:
	virtual bool mouvementValide(int pas) = 0;
	virtual void deplacer(std::pair<char, int> pair) = 0;
	std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1}};

private:
	int x_ = 0;
	int y_ = 0;
	std::pair<int, int> position;
	char symbole = 'P';
};

class Roi : public Piece {
public:
	Roi();
	bool mouvementValide(int pas) override;
	void deplacer(std::pair<char, int> pair) override;
	~Roi();
	static int inline compteurInstance;

	std::pair<int, int> position;
	char symbole = 'K';
private:

	int x_ = position.first;
	int y_ = position.second;

};

class InstancesRoiException : public std::logic_error
{
public:
	using std::logic_error::logic_error;
};

class Reine : public Piece {
public:
	bool mouvementValide(int pas) override;
	void deplacer(std::pair<char, int> pair) override;

	std::pair<int, int> position = {};
	char symbole = 'Q';

private:

	int x_ = position.first;
	int y_ = position.second;
};

class Tour : public Piece {
public:
	bool mouvementValide(int pas) override;
	void deplacer(std::pair<char, int> pair) override;

	std::pair<int, int> position;
	char symbole = 'T';
private:

	int x_ = position.first;
	int y_ = position.second;

};

class Echiquier {
public:
	Echiquier();
	void modifierBoard(int x, int y, char symbole);
	void synchroniserBoard();
	void afficher();
	/*const std::shared_ptr<Roi> getRoiA() const;
	const std::shared_ptr<Reine> getReineA() const;
	const std::shared_ptr<Tour> getTourA() const;*/
private:
	Roi roiA;
	Roi roiB;
	Reine reineA;
	Reine reineB;
	Tour tourAA;
	Tour tourAB;
	Tour tourBA;
	Tour tourBB;
	char board[8][8] = {}; //[colonne] [ligne]

};