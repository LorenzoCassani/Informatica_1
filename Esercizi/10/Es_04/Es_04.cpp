#include "../../lib.h"

using namespace std;

int main(){

	myArrayInt v;

	v.size=0;
    	v.used=0;
    	v.raw=NULL;

    	v=caricaArrayFile("datiInteri.dat");

	cout << endl << "L'array ha dimensione: " << v.size << endl;
    	cout << endl << "L'array ha " << v.used << " elementi caricati" << endl;

	mergeSort(v.raw,0,v.used-1);

	findCount(v.raw,v.size,v.used);

	return 0;
}
