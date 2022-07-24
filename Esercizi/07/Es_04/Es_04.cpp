#include "../../lib.h"

using namespace std;

int main(int argc, char* argv[]){

	if(argc!=3){
		cout << "Usage: " << argv[0] << " nomeFileInput nomeFileOutput" << endl;
		return 1;
	}

	int m;
	int n;

	ifstream in;
   	ofstream out;
	
	in.open(argv[1]);

	if(in.fail()){
        	cerr << endl <<"ERRORE: il file " << argv[0] << " non è presente nella cartella!" << endl;
   		return 1; 
    	}
	
	in >> m;
	in >> n;

	//ALLOCAZIONE DINAMICA DI UNA MATRICE
	float** dynMatr;
	dynMatr=new float*[m]; //Alloco l'array di puntatori

	for(int i=0; i<m; ++i)
		dynMatr[i]=new float[n]; //Per ogni puntatore dell'array alloco un array di float

	//RIEMPIMENTO MATRICE	
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			in >> dynMatr[i][j];
		}
	}

	in.close();

	out.open(argv[2]);

	cout << endl;

	//STAMPO LA MATRICE A TERMINALE E SUL FILE DI OUTPUT
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cout << dynMatr[i][j] << "\t"; //Spazio di tab tra elementi
			out << dynMatr[i][j] << "\t";
		}
		cout << endl; //Mando a capo alla fine di ogni riga
		out << endl;
	}

	out.close();

	cout << endl << "Il file " << argv[2] << " contiene una copia della matrice" << endl;

	//DEALLOCAZIONE DI UNA MATRICE ALLOCATA DINAMICAMENTE
	for(int i=0; i<m; ++i)
		delete[] dynMatr[i]; //Dealloco ogni array di dati
	delete[] dynMatr; //Dealloco l'array di puntatori

	return 0;
}
	
