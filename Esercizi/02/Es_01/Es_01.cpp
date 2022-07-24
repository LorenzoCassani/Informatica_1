#include <iostream>
using namespace std;

int main(){

	int a, b;
	int somma, diff, ratio, mod;

	cout << "Inserire due numeri int a e b" << endl;
	cin >> a >> b;
	somma=a+b, diff=a-b;
	cout << "a+b = " << somma << endl;
	cout << "a-b = " << diff << endl;
	if(b!=0){
		ratio=a/b, mod=a%b;
		cout << "a/b = " << ratio << endl;
		if(mod==0)
			cout << "a è un multiplo intero di b" << endl;
		else
			cout << "a non è un multiplo intero di b" << endl;
		if(mod<0)
			mod=mod*(-1);
		cout << "Il resto di a/b e' : " << mod << endl;
	}
	//Se inserissi b=0, avrei un errore di core dump (il divisore non può essere 0)
	else
		cerr << "Il divisore non puo' essere 0!" << endl;
	return 0;
}


