#include "../../lib.h"

using namespace std;

int main(){

    	myArrayInt v;

	v.size=0;
    	v.used=0;
    	v.raw=NULL;

    	v=caricaArrayFile("datiInteri.dat");
    	print(v);

	return 0;
}
