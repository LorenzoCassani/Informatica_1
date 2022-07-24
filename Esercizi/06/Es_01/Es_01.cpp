#include "../../lib.h"

#define N 200

using namespace std;

int main(){

	int quanti=0;
	int quantiNew;
    	float *dati=NULL;
    	float appo;
	float m;
	float stdDevC;
	float mNew;
	float stdDevCNew;	

    	ifstream in;
    	ofstream out;
	
	//CONTO I DATI CONTENUTI NEL FILE DI INPUT
    	in.open("misure.dat");
	
	//Controllo errori
    	if(in.fail()){
        	cerr << endl <<"ERRORE: il file misure.dat non è presente nella cartella!" << endl;
   		return 1; 
    	}
 
    	in >> appo;
    	while(!in.eof() ){ //.eof() restituisce true se il file è finito false atrimenti
    		quanti++;
    		in >> appo;
    	}
	cout << endl <<"Il file misure.dat contiene " << quanti << " dati" << endl;
    	in.close();


	//CARICO I DATI DAL FILE DI INPUT
    	in.open("misure.dat");
	    
    	//Creo contenitore per i dati
    	dati = new float[N];

    	for(int i=0; i<quanti; i++){
        	in >> dati[i];
    	}
    	in.close();

	cout << endl << "CAMPIONE PRE-SCREMATURA: " << endl;
	for(int i=0; i<quanti; i++)
		cout << endl << "dati[" << i <<"] = " << dati[i];

	m = media(dati,quanti);
    	stdDevC = sqrt(varCamp(dati,quanti));

    	quantiNew = quanti;

    	for(int i=0; i<quantiNew; i++){
        	if(fabs(dati[i]-m)>3*stdDevC){ //la funzione fabs si trova nella libreria cmath
        		dati[i]=dati[quantiNew-1];
            		quantiNew--;
            		i--;
        	}
    	}

	mNew = media(dati,quantiNew);
    	stdDevCNew = sqrt(varCamp(dati,quantiNew));


	//COPIO I DATI NEL FILE DI OUTPUT (se non esiste viene creato)
    	out.open("scremati.dat");

	out << endl << "DATI PRE-SCREMATURA: " << endl;
	out << endl << "N° = " << quanti << endl;
	out << endl << "media = " << m << endl;
	out << endl << "deviazione standard = " << stdDevC << endl;

	out << endl << "Il processo di scrematura ha eliminato " << quanti-quantiNew << " dati" << endl;

	out << endl << "DATI POST-SCREMATURA: " << endl;
	out << endl << "N° = " << quantiNew << endl;
	out << endl << "media = " << mNew << endl;
	out << endl << "deviazione standard = " << stdDevCNew << endl;

	out << endl << "NUOVO CAMPIONE: " << endl;

	for(int i=0; i<quantiNew; i++)
		out << endl << "dati[" << i <<"] = " << dati[i];

	out.close();

	
    	delete [] dati;
    	dati=NULL;

	cout << endl << endl << "OPERAZIONE DI SCREMATURA ESEGUITA (controllare il file scremati.dat)" << endl;

    	return 0;

}

