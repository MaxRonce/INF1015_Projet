#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <map>


class Piece {
public:
	virtual bool mouvementValide(int pas) = 0;
	virtual void deplacer(char x, int y) = 0;
	std::map<char, int> map{ {'A', 8}, {'B', 7},{'C', 6},{'D', 5},{'E', 4}, {'F', 3}, {'G', 2},{'H', 1}};
	virtual const std::pair<int, int> getPosition() const = 0;
	virtual const std::pair<int, int> getPositionPrecedente() const = 0;
	virtual void setPositionPrecedente() = 0;
	virtual const char getSymbole() const = 0;

private:
	std::pair<int, int> position;
	std::pair<int, int> positionPrecedente;
	char symbole = 'P';
	int x_ = 0;
	int y_ = 0;
};

class Roi : public Piece {
public:
	Roi();
	bool mouvementValide(int pas) override;
	void deplacer(char x, int y) override;
	const std::pair<int, int> getPosition() const override;
	const std::pair<int, int> getPositionPrecedente() const override;
	void setPositionPrecedente() override;
	const char getSymbole() const override;
	~Roi();
	static int inline compteurInstance;

private:

	std::pair<int, int> positionPrecedente;
	std::pair<int, int> position;
	char symbole = 'K';
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
	void deplacer(char x, int y) override;
	const std::pair<int, int> getPosition() const override;
	const std::pair<int, int> getPositionPrecedente() const override;
	void setPositionPrecedente() override;
	const char getSymbole() const override;

private:
	std::pair<int, int> position;
	std::pair<int, int> positionPrecedente;
	char symbole = 'Q';

	int x_ = position.first;
	int y_ = position.second;
};

class Tour : public Piece {
public:
	bool mouvementValide(int pas) override;
	void deplacer(char x, int y) override;
	const std::pair<int, int> getPosition() const override;
	const std::pair<int, int> getPositionPrecedente() const override;
	void setPositionPrecedente() override;
	const char getSymbole() const override;
private:

	std::pair<int, int> position;
	std::pair<int, int> positionPrecedente;
	char symbole = 'T';
	int x_ = position.first;
	int y_ = position.second;

};

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