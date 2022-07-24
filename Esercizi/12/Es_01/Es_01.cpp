#include "../../lib.h"

using namespace std;

//Questo è un programma che ho utilizzato per testare i metodi delle classi elemInt e stackInt

int main(){

	stackInt pila;
    	int pippo;
		
    	cout << endl << "Programma prova stack" << endl;

    	cout << endl <<"Prima stampa: è vuoto? " <<  pila.isEmpty() << endl;

    	pila.push(5);

    	cout << endl <<"Seconda stampa: è vuoto? " <<  pila.isEmpty()<< endl;
    	//Non si può (il campo head è private):
    	//cout << endl << " Head = " << pila.head << endl;
    	pippo=pila.top();

    	cout << endl << "Terza stampa: " << endl;
    	cout << "Value: " << pippo << endl;

    	pila.push(3);
    	pippo=pila.top();
    	cout << endl << "Quarta stampa: " << endl;
    	cout << "Value: " << pippo << endl;

	return 0;
}
