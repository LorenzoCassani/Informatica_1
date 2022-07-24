#include <iostream>

#define DIM 100 // Definizione di una costante numerica

using namespace std;

int main(){
	
	float x0;
	float v;
	float dt;
	float pos[DIM];
	int k=0;

	cout << "Programma di simulazione: moto rettilineo uniforme" << endl;
	cout << endl << "Inserire la posizione iniziale del punto materiale (cm):   x0 = ";
	cin >> x0;
	cout << endl << "Inserire la velocita' del punto materiale (cm/s):   v = ";
	cin >> v;
	cout << endl << "Inserire l'incremento temporale di ogni passo (s):   dt = ";
	cin >> dt;
	cout << endl << "Legge oraria: x(t) = "<< x0 << " + " << v << "*t"<< endl;
	
	cout << endl << "t:    " << "x:" << endl;

	//Carico la posizione iniziale nell'array 

	pos[0] = x0;

	//Carico l'array con le restanti posizioni

	for(int i=1; i<DIM; i++)
		pos[i] = x0+v*(dt*i);

	//Stampo l'array

	for(int i=0; i<DIM; i++)
		cout << dt*i << "   " << pos[i] << endl;

	while ((pos[k]*pos[k+1] >= 0) and k<99)
        	k++;

    	if(k==99){
        	cout <<endl <<" La posizione non cambia segno" << endl;}
    	else{
    		cout << endl << "Intervallo cambio di segno della posizione: [" << dt*k << "," <<dt*(k+1) <<"]" << endl;
    	}

	return 0;

}

// Per x0=-0.5 cm, v=1.5 cm/s, dt=0.2 s, la posizione cambia segno tra 0.2 e 0.4 secondi
