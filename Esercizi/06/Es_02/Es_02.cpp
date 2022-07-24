#include "../../lib.h"

using namespace std;

int main(){

	const int M=5;
	const int N=5;

	float matr[M][N];

	int nRows;
	int nCols;

	int posMini=0, posMinj=0, posMaxi=0, posMaxj=0;

	float somma=0;
	float media=0;
	float somma2=0;
	float varianza=0;
	int rVarMin=0, rVarMax=0;
	
	ifstream in;
    	ofstream out;
	
	in.open("matrice.dat");
	
    	if(in.fail()){
        	cerr << endl <<"ERRORE: il file matrice.dat non è presente nella cartella!" << endl;
   		return 1; 
    	}

	in >> nRows;
	in >> nCols;

	if(nRows>M or nCols>N){
		cerr << endl << "ERRORE: la matrice contenuta nel file matrice.dat ha un numero di righe e/o di colonne superiore a quello supportato dal programma!" << endl;
	return 1;
	}

	//CARICO I DATI DAL FILE DI INPUT
	for(int i=0; i<nRows; ++i){
		for(int j=0; j<nCols; ++j){
        		in >> matr[i][j];
    		}
	}

	in.close();

	//STAMPO LA MATRICE A TERMINALE
	for(int i=0; i<nRows; ++i){
		for(int j=0; j<nCols; ++j){
			cout << matr[i][j] << "\t"; //Spazio di tab tra elementi
		}
		cout << endl; //Mando a capo alla fine di ogni riga
	}
	
	int posmini=0, posminj=0, posmaxi=0, posmaxj=0;
	
	//MINIMO E MASSIMO DELLA MATRICE (IN MODULO)
	for(int i=0; i<nRows; ++i){
		for(int j=0;j<nCols;++j){
			if(fabs(matr[i][j])<fabs(matr[posMini][posMinj])){
	                	posMini=i;
	                	posMinj=j;
	            	}
			else if(fabs(matr[i][j])>fabs(matr[posMaxi][posMaxj])){
	                	posMaxi=i;
	                	posMaxj=j;
	            	}
		}
	}

	cout << endl << "Posizione minimo (in modulo): i=" << posMini+1 << ", j=" << posMinj+1;
	cout << endl << "Posizione massimo (in modulo): i=" << posMaxi+1 << ", j=" << posMaxj+1 << endl;

	//MEDIA E VARIANZA DEL CAMPIONE (PER RIGA)
	cout << endl;
	for(int i=0; i<nRows; i++){
		for(int j=0; j<nCols; j++){
			somma+=matr[i][j]; //a+=b significa a=a+b
			somma2+=matr[i][j]*matr[i][j];
		}
		media=somma/nCols;

		if(somma2/nCols-pow(media,2)<varianza)
			rVarMin=i;

		if(somma2/nCols-pow(media,2)>varianza)
			rVarMax=i;
			
		varianza=somma2/nCols-pow(media,2);
		
		cout << "Media riga " << i+1 << "=" << media << endl;
		cout << "Varianza riga " << i+1 << "=" << varianza << endl;
		cout << endl;
	}

	cout << "Riga avente la varianza del campione minima: " << rVarMin+1 << endl;
	cout << "Riga avente la varianza del campione massima: " << rVarMax+1 << endl;	

	return 0;
}

	
