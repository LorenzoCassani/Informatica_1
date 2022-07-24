#include "../../lib.h"

using namespace std;

int main(){

	palla ball;
    	palla* pball;
	pball=new palla;

    	ifstream in;

    	cout << endl << "Dimensione puntatore: " << sizeof(float*) << " byte" << endl;

    	in.open("struttura.dat");

    	if(in.fail()){
    		cerr << endl << "ERRORE: il file struttura.dat non è presente nella cartella!" << endl;
        	return 1;
    	}

    	in >> ball.colore;
    	in >> ball.cod;
    	in >> ball.pos[0] >> ball.pos[1];
    	in >> ball.massa;
    	in >> ball.raggio;

	in.close();

	cout << endl << "Contenuto del dato di tipo struct: ball ";
    	cout << endl << "Colore: " << ball.colore;
    	cout << endl << "Codice: " << ball.cod;
    	cout << endl << "Posizione iniziale: " << ball.pos[0] <<"	Posizione finale: " <<  ball.pos[1];
    	cout << endl << "Massa: " << ball.massa;
    	cout << endl << "Raggio: " << setprecision(14) << ball.raggio;
    	cout << endl;

    	cout <<  endl << "Utilizzo la funzione caricaStructPalla..." << endl;

    	caricaStructPalla("struttura.dat",pball);

    	if(pball==NULL){
        	cout << endl <<"Problema in funzione di caricamento" << endl;
    	}

	cout << endl << "Contenuto del dato di tipo struct: pball ";
    	//cout << endl << "Colore: " << (*pball).colore; //Metodo 1
    	cout << endl << "Colore: " << pball->colore;  //Metodo 2
	cout << endl << "Codice: " << pball->cod;
    	cout << endl << "Posizione iniziale: " << pball->pos[0] <<"	Posizione finale: " <<  pball->pos[1];
    	cout << endl << "Massa: " << pball->massa;
    	cout << endl << "Raggio: " << setprecision(14) << pball->raggio;
    	cout << endl;
	
    	delete pball;

    	return 0;
}

