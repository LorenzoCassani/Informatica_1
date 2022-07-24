#include "../../lib.h"

using namespace std;

int main(){
	int dim=10;//allocando un array in maniera statica non posso sceglierne la dimensione a runtime (pena crash del programma) 
	float vettore[dim];
	cout << "Dimensione dell'array: " << dim << endl;
	for(int i=0; i<dim; i++){
		cout << "Inserisci il dato da caricare in posizione " << i << " dell'array" << endl;
		cin >> vettore[i];
	}
	cout << "Array disordinato: " << endl;
	stampa(vettore,dim);
	selectionSort(vettore,dim);
	cout << endl;
	cout << "Array ordinato: " << endl;
	stampa(vettore,dim);
}

		
		
	
