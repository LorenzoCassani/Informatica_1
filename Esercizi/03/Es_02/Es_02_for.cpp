#include <iostream>
#include <cmath>

using namespace std;

float caricavoti();

int main(){

	int N;
	float appo;
	float tot=0, tot2=0;
	float media, varC;
	float min, max;

	cout << "Di quanti voti vuoi fare la media aritmetica?" << endl;
	cin >> N;
	cout <<"Inserisci " << N << " voti" << endl;

	//versione for	

	for(int i=0; i<N; i++){
		appo = caricavoti();
		if(i==0){
			min=appo;
			max=appo;
		}
		else{
			if(appo>max){
				max=appo;
			}
			if(appo<min){
				min=appo;
			}
		}
		tot=tot+appo;
		tot2=tot2+appo*appo;
	}

	media=(float)tot/N;
	varC=(float)tot2/N-media*media;
	cout << "Media: " << media << endl << "Varianza: " << varC << endl;
	cout << "Minimo: " << min << endl <<"Massimo: " << max << endl;
	return 0;
}

float caricavoti(){
	float appo;
	do{
		cout << "Inserire voto (compreso tra 18 e 30): ";
		cin >> appo; 
	}while(appo <18 or appo>30);
	return appo;
}

