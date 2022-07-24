#include <iostream>
#include <ctime>
#include <cstdlib> // rand

using namespace std;

int giocaComputer();

int main(){

	char seme;
	int umano;
	int computer;
	int somma;

	do{
		cout << "Pari o dispari? (inserire p oppure d)" << endl;
		cin >> seme;
	}while(seme!='p' and seme!='d');

	do{
		cout << "Scegli un numero da 1 a 5!" << endl;
		cin >> umano;
	}while(umano<1 or umano>5);

	cout << endl << "bim" << endl << endl << "bum" << endl << endl << "bam!" << endl << endl;	

	computer = giocaComputer();
	
	somma = umano+computer;

	cout << "La tua giocata: " << umano << endl;
	cout << "La giocata del computer: " << computer << endl;

	if(seme=='p'){
		if(somma%2==0)
			cout << "Hai vinto!" << endl;
		else
			cout << "Hai perso." << endl;
	}

	if(seme=='d'){
		if(somma%2!=0)
			cout << "Hai vinto!" << endl;
		else
			cout << "Hai perso." << endl;
	} 
	
	return 0;
}

int giocaComputer(){

    int caso;

    srand(time(NULL));

    caso=rand();

    return caso%6; //L'operazione di divisione di un numero intero per 6 ha come resto un valore compreso tra 0 e 5

}















