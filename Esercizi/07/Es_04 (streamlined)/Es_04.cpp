#include "../../lib.h"

using namespace std;

int main(int argc, char* argv[]){

	if(argc!=3){
		cout << "Usage: " << argv[0] << " nomeFileInput nomeFileOutput" << endl;
		return 1;
	}

	int nRows;
	int nCols;

	ifstream in;
   	ofstream out;
	
	in.open(argv[1]);

	if(in.fail()){
        	cerr << endl <<"ERRORE: il file " << argv[0] << " non è presente nella cartella!" << endl;
   		return 1; 
    	}
	
	in >> nRows;
	in >> nCols;

	float matr[nRows*nCols]; //Versione streamlined

	//RIEMPIMENTO MATRICE	
	for(int i=0; i<nRows*nCols; ++i){
		in >> matr[i];
	}

	in.close();

	out.open(argv[2]);

	cout << endl;

	//STAMPO LA MATRICE A TERMINALE E SUL FILE DI OUTPUT (METODO 1: funzione at)
	float elemento;

	for(int i=0; i<nRows; ++i){ 
        	for(int j=0; j<nCols and j<nRows*nCols; ++j){
			elemento = at(matr,i,j,nRows,nCols); 
                	cout << elemento << "\t";
			out << elemento << "\t";
         	}  
            	cout << endl;
		out << endl;
      	}		
	
	/*//STAMPO LA MATRICE A TERMINALE E SUL FILE DI OUTPUT (METODO 2: NO funzione at)
	for(int i=0; i<nRows*nCols; i+=nCols){ 
        	for(int j=i; j<nCols+i and j<nRows*nCols; ++j){ 
                	cout << matr[j] << "\t";
			out << matr[j] << "\t";
         	}  
            	cout << endl;
		out << endl;
      	}*/

	out.close();

	cout << endl << "Il file " << argv[2] << " contiene una copia della matrice" << endl;

	return 0;
}
	
