#include "../../lib.h"

using namespace std;

int main(){

	int dim;

    	myArrayInt v;

	v.size=0;
    	v.used=0;
    	v.raw=NULL;

    	cout << endl << "Dimensione vettore: " ;
    	cin >> dim;

    	v.size=dim;
    	v.raw = new int[v.size];

    	cout << endl << "Inserire dati: " << endl;
    	for(int i=0; i<v.size;i++){
        	cin >> v.raw[i];
        	v.used++;
    	}

    	print(v);
   
    	cout << endl << "Inserire nuova dimensione del vettore: ";
    	cin >>dim;

    	resize(&v.raw,v.size,dim);
    	v.size=dim;
    	print(v);

    	v=caricaArrayFile("datiInteri.dat");
    	print(v);

	return 0;
}
