#include "echecs.h"
#include < stdlib.h >
using namespace std;


//TODO:-Completer les fcts deplacer des pieces : DONE
//Creer une map des coordonnees + attribut position+updater le board DONE 
//gerer les hors map dans mvmnt valide. N:b fct mvmnt valide doit etre appele dans deplacer() avant de deplacer sinon execption
vector<shared_ptr<Piece>> f();



int main() {
	char x = 0;
	int y = 0 ;
	try{
		Echiquier echiquier;
		auto vec = f();
		for (auto&& elem : vec) {
			echiquier.pieces.push_back(elem);
		}
		echiquier.initialisation();
		cout << "Welcome Player, To Chess Game\n";
		while(true) {
		echiquier.afficher();
		/*cout << "\nPlease choose piece to move :\n";
		cin >> x >> y;
		echiquier.piece(x, y);*/
		cout << "\nYour next move : \n";
		cin >> x >> y;
		echiquier.pieces[0]->deplacer(x, y);
		system("CLS");
		}
	}
	catch(InstancesRoiException& except){
		cout << "Erreur d'execution : " << except.what() << endl;
	}
}
vector<shared_ptr<Piece>> f(){
	vector<shared_ptr<Piece>> vec;
	Roi roiA;
	vec.push_back(make_shared<Roi>(roiA));
	Roi roiB;
	vec.push_back(make_shared<Roi>(roiB));
	Reine reineA;
	vec.push_back(make_shared<Reine>(reineA));
	Reine reineB;
	vec.push_back(make_shared<Reine>(reineB));
	Tour tourAA;
	vec.push_back(make_shared<Tour>(tourAA));
	Tour tourAB;
	vec.push_back(make_shared<Tour>(tourAB));
	Tour tourBA;
	vec.push_back(make_shared<Tour>(tourBA));
	Tour tourBB;
	vec.push_back(make_shared<Tour>(tourBB));
	return vec;
}
