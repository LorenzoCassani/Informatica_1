#include "../../lib.h"
 
#define N 50

using namespace std;

int main(){

    int dim;

    float min,max,m,varC,dati[N];
    int posMin, posMax;

    dim = caricaDati(dati,N);
    stampa(dati,dim);
    m = media(dati,dim);
    varC = varCamp(dati,dim); 
    posMin=trovaMin(dati,dim);
    posMax=trovaMax(dati,dim);
   
    cout << endl << "Caricati: " << dim << " dati." << endl;
    cout << "Media= " << m << endl;
    cout << "Varianza Campione= " << varC << endl;
    cout << "Minimo= " << dati[posMin] <<" in posizione: " << posMin << endl;
    cout << "Massimo= " << dati[posMax] <<" in posizione: " << posMax << endl;

    swapArrayFloat(dati,posMin,posMax);

    cout << "Scambio di posizione minimo e massimo..." << endl;

    cout << "Minimo= " << dati[posMax] <<" in posizione: " << posMax << endl;
    cout << "Massimo= " << dati[posMin] <<" in posizione: " << posMin << endl;

    return 0;
}




