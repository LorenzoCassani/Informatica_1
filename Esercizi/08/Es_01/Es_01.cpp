#include "../../lib.h"

#define NMISURE 50

using namespace std;

int main(){

	float l=2;

	initRand();

	ofstream out;

	out.open("risultatiPi.dat");

	out << "MONTE CARLO: stima pi" << endl;

	out << endl <<"nPunti\t\tMedia\t\tSigma\t\tTempo di esecuzione [s]" << endl;

	for(int i=50; i<=1000; i+=50){

		clock_t start, end;

		start=clock();

		float* arr=esperimentoPi(i,l,NMISURE);

		end=clock();

		float time=(float)(end-start)/CLOCKS_PER_SEC;

		out << endl << i << "\t\t" << media(arr,NMISURE) << "\t\t" << sqrt(varCamp(arr,NMISURE)) << "\t\t" << time << endl;

		delete[] arr;
	}

	out.close();

	cout << endl << "SIMULAZIONE COMPLETATA: i risultati sono contenuti nel file risultatiPi.dat" << endl;
	cout << endl;	

	return 0;
}
