#include "echecs.h"
#include < stdlib.h >
using namespace std;

//TODO:-Completer les fcts deplacer des pieces : DONE
//Creer une map des coordonnees + attribut position+updater le board DONE 
//gerer les hors map dans mvmnt valide. N:b fct mvmnt valide doit etre appele dans deplacer() avant de deplacer sinon execption




int main() {
	char x = 0;
	int y = 0 ;
	try{
		Echiquier echiquier;
		cout << "Welcome Player, To Chess Game\n";
		while(true) {
		echiquier.afficher();
		/*cout << "\nPlease choose piece to move :\n";
		cin >> x >> y;
		echiquier.piece(x, y);*/
		cout << "\nYour next move : \n";
		cin >> x >> y;
		echiquier.reineA.deplacer(x, y);
		system("CLS");
		}
	}
	catch(InstancesRoiException& except){
		cout << "Erreur d'execution : " << except.what() << endl;
	}
}