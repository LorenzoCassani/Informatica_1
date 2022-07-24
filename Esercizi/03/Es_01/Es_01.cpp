#include <iostream>
#include <cmath> //E' necessario includere cmath per utilizzare pow

using namespace std;

//Protipi/dichiarazione delle funzioni

float media(int,int);

float varC(int,int);

//main

int main(){

	int n1, n2;
	int min, max;

	do{
        	cout << "Inserire primo voto (compreso tra 18 e 30): ";
        	cin >> n1;
    	}while(n1<18 or n1>30);

    	do{
        	cout << "Inserire secondo voto (compreso tra 18 e 30): ";
        	cin >> n2;
    	}while(n2<18 || n2>30);

	cout << "La media tra i due voti è: " << media(n1, n2) << endl;
	cout << "La varianza tra i due voti è: " << varC(n1, n2) << endl;
	if(n1>n2){ 
		max=n1;
		cout << "Il massimo tra i due voti e' : " << max << endl;
		min=n2;
		cout << "Il minimo tra i due voti e' : " << min << endl;
	}
	else{
		max=n2;
		cout << "Il massimo tra i due voti e' : " << max << endl;
		min=n1;
		cout << "Il minimo tra i due voti e' : " << min << endl;
	}
	return 0;
}

//Implementazione delle funzioni

float media(int x, int y){
	return (float)(x+y)/2;
}

float varC(int x,int y){
	return (float)(x*x+y*y)/2-pow(media(x,y),2);
}
