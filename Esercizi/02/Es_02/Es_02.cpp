#include <iostream>
using namespace std;

//Un numero intero occupa 4 byte di memoria, ovvero 32 bit. Il segno occupa uno di questi 32 bit.
//Il numero intero (positivo) più grande rappresentabile è: 2^31-1 = 2147483647 (partendo da 0).
//Il numero intero (negativo) più grande rappresentabile è: -2^31 = -2147483648 (partendo da -1).

int main(){
	int N;
	cout << "Inserire un numero intero N a cui sommare 10" << endl;
	cin >> N;
	cout << "N+10 = " << N+10 << endl;
	return 0;
}

//Risultati: una volta passato il limite int, il computer ricomincia a contare dall'int minimo, ovvero -2^31.
