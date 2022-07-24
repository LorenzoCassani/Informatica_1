#include "../../lib.h"

using namespace std;

int main(){
	
	float x0;
	float v;
	float tMax;
	float dt;
	int nsteps;
	int k=0;

	srand(time(NULL));

	cout << "Programma di simulazione: moto rettilineo uniforme" << endl;
	cout << endl << "Inserire la posizione iniziale del punto materiale (cm):   x0 = ";
	cin >> x0;
	cout << endl << "Inserire la velocita' del punto materiale (cm/s):   v = ";
	cin >> v;
	cout << endl << "Inserire il tempo finale (s): tMax = ";
	cin >> tMax;
	cout << endl << "Inserire il passo di integrazione (s):   dt = ";
	cin >> dt;

	//Calcolo il numero di passi
	nsteps = (tMax/dt)+1;

	float pos[nsteps];
	float vel[nsteps];

	cout << endl << "Legge oraria: x(t) = "<< x0 << " + " << v << "*t"<< endl;
	cout << endl << "t:     " << "x:     " << "v:     " << endl;

	//Carico il primo elemento dei due array
	pos[0] = x0;
	vel[0] = v;

	//Carico i restanti elementi degli array
	for(int i=1; i<nsteps; i++){
		
		//Assegno un errore casuale all'i-esima posizione
		float epsilon;
    		
    		epsilon = randUnif(-0.3,0.3);

		pos[i] = x0+v*(dt*i)+epsilon;
		
		vel[i] = (pos[i]-pos[i-1])/dt;
	}

	//Stampo l'array
	for(int i=0; i<nsteps; i++)
		cout << dt*i << "   " << pos[i] << "   " << vel[i] << endl;

	//Media del campione delle velocità
	float mediavel = media(vel,nsteps);
	cout << endl << "Media del campione delle velocità: " << mediavel << " m/s" << endl;

	//Deviazione standard del campione delle velocità
	float sigmavel = sqrt(varCamp(vel,nsteps));
	cout << endl << "Deviazione standard del campione delle velocità: " << sigmavel << " m/s" << endl;

	//Confronto fra media del campione delle velocità e velocità media
	float vm = (pos[nsteps-1]-x0)/(dt*nsteps);
	cout << endl << "Velocità media: " << vm << " m/s" << endl;

	if(mediavel==vm)
		cout << endl << "La media del campione delle velocità e la velocità media coincidono!" << endl;
	else
		cout << endl << "La media del campione delle velocità e la velocità media non coincidono." << endl;

	return 0;

}
