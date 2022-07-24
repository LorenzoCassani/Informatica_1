#include "../../lib.h"

using namespace std;

int main(int argc, char* argv[]){

	if(argc!=3){
		cout << "Usage: " << argv[0] << " nomeFileDaCopiare nomeFileCopia" << endl;
		return 1;
	}

   	char appo;

	int contaCaratteri=0;
	int contaSpazi=0;
	int contaRighe=-1; //Parto da -1 perchè il programma legge una riga in più di default
	int contaDoppie=0;
	
	ifstream in;
   	ofstream out;
	
	in.open(argv[1]);

	if(in.fail()){
        	cerr << endl <<"ERRORE: il file " << argv[0] << " non è presente nella cartella!" << endl;
   		return 1; 
    	}

	out.open(argv[2]);	
	
	cout << endl << "CONTENUTO DEL FILE:" << endl;

    	while(!in.eof()){
		in.get(appo); //Leggi carattere
        	cout << appo; //Stampa a video
        	out.put(appo); //Stampa su file
        	
		if(appo=='\n') //Conta le righe
			contaRighe++;

		else if(appo==' ') //Conta gli spazi
			contaSpazi++;

		else
			contaCaratteri++;
    	}

	in.close();
	out.close();

	//CONTO LE DOPPIE

	in.open(argv[1]); //Riapro l'instream per caricare il vettore di char con i caratteri 

	char doppie[contaCaratteri];

	in >> doppie[contaCaratteri];

	int i=0;
	while(!in.eof()){
		i++;
	    	in >> doppie[i];
	}
	
	for(int i=0; i<=contaCaratteri; i++){
		if(doppie[i]==doppie[i+1])
			contaDoppie++;
	}

	cout << "Numero caratteri: " << contaCaratteri << endl;
	cout << "Numero spazi: " << contaSpazi << endl;
	cout << "Numero righe: " << contaRighe << endl;
	cout << "Numero doppie: " << contaDoppie << endl;

	in.close();

    	return 0;
}
