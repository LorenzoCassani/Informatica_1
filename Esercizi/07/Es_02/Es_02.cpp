#include "../../lib.h"

using namespace std;

int main(){

	float p1;
	float p2;	

	cout << "Questo programma scambia il contenuto di due variabili p1 e p2" << endl;
	cout << endl << "Inserire il valore di p1: ";
	cin >> p1;
	cout << endl << "Inserire il valore di p2: ";
	cin >> p2;
	cout << endl << "PRE-SCAMBIO: p1=" << p1 << ", p2=" << p2 << endl;
	swap(&p1,&p2);
	cout << endl << "POST-SCAMBIO: p1=" << p1 << ", p2=" << p2 << endl;

	return 0;
}
