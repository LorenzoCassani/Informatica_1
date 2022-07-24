#include <iostream>
using namespace std;

int main(){

	float a, b;
	float somma, diff, ratio;

	cout << "Inserire due numeri float a e b" << endl;
	cin >> a >> b;
	somma=a+b, diff=a-b;
	cout << "a+b = " << somma << endl;
	cout << "a-b = " << diff << endl;
	if(b!=0){
		ratio=a/b;
		cout << "a/b = " << ratio << endl;
	}
	//Se inserissi b=0, mi verrebbe restituito a/b=inf(inito) (per via della rappresentazione floating point)
	else
		cerr << "Il divisore non puo' essere 0!" << endl;
	return 0;
}

