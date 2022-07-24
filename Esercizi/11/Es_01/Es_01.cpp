#include "../../lib.h"

using namespace std;

//Questo è un programma che ho utilizzato per testare i metodi della classe myArrayFloat

int main(){

	myArrayFloat v;

	v.initialize("datiInteri.dat");

	v.sort();

	for(int i=0; i<83; i++)
		cout << v.at(i) << endl;

	return 0;
}
