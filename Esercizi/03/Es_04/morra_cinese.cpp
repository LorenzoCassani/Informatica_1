#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int giocaComputer();

int main(){
	
	int umano;
	int computer;

	do{
		cout << "Scegli: carta(1), forbice(2) o sasso(3)?" << endl;
		cin >> umano;
	}while(umano<1 or umano>3);

	cout << endl << "carta" << endl << endl << "forbice" << endl << endl << "sasso!" << endl << endl;

	computer = giocaComputer();

	if(umano==1)
		cout << "La tua giocata: Carta" << endl;
	if(umano==2)
		cout << "La tua giocata: Forbice" << endl;
	if(umano==3)
		cout << "La tua giocata: Sasso" << endl;
	if(computer==1)
		cout << "La giocata del computer: Carta" << endl;
	if(computer==2)
		cout << "La giocata del computer: Forbice" << endl;
	if(computer==3)
		cout << "La giocata del computer: Sasso" << endl;

	if(umano==1){
		if(computer==1)
			cout << "Pareggio" << endl;
		if(computer==2)
			cout << "Hai perso" << endl;
		if(computer==3)
			cout << "Hai vinto!" << endl;
	}
	if(umano==2){
		if(computer==1)
			cout << "Hai vinto!" << endl;
		if(computer==2)
			cout << "Pareggio" << endl;
		if(computer==3)
			cout << "Hai perso" << endl;
	}
	if(umano==3){
		if(computer==1)
			cout << "Hai perso" << endl;
		if(computer==2)
			cout << "Hai vinto!" << endl;
		if(computer==3)
			cout << "Pareggio" << endl;
	}

	return 0;
}

int giocaComputer(){

    int caso;

    srand(time(NULL));

    caso=rand();

    return (caso%3+1); //In questo modo il computer "sceglie" sempre un valore compreso tra 1 e 3

}	
