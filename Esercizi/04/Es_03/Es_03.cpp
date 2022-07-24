#include "../../lib.h"

using namespace std;

int main(){

	int a, b, res[2];

	cout << endl << "Programma: divisione euclidea" << endl;
	cout << endl << "a = b x q + r" << endl;
	cout << endl << "0 <= r < |b|" << endl;
	
	divEucl(a, b, res);

	if(res[1]!=-1)

		cout << endl << "a/b = " << res[0] << "	resto: " << res[1] << endl;	
	
	return 0;
}
