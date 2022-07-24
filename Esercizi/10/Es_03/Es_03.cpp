#include "../../lib.h"

using namespace std;

int main(){

	myArrayInt v;

	v.size=0;
    	v.used=0;
    	v.raw=NULL;

    	v=caricaArrayFile("datiInteri.dat");

	cout << endl << "ARRAY DISORDINATO:" << endl;

	print(v);

	mergeSort(v.raw,0,v.used-1);

	cout << endl << "ARRAY ORDINATO:" << endl;

	print(v);
    	
	return 0;
}
