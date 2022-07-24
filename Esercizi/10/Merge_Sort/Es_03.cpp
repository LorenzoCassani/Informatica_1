#include "../../lib.h"

using namespace std;

int main(){

    	int num, i;

    	int a[50];

    	cout << "********************************************************************************" << endl;
    	cout << "                             MERGE SORT PROGRAM " << endl;
    	cout << "********************************************************************************" << endl;
    	cout << endl << endl;

    	cout << "Please Enter THE NUMBER OF ELEMENTS you want to sort:" << endl;
    	cin >> num;
    	cout << endl;
    	cout << "Now, Please Enter the ( "<< num <<" ) numbers (ELEMENTS):" << endl;
    	for(i=0; i<num; i++){
        	cin >> a[i];
    	}
    
    	mergeSort(a,0,num-1); //Chiamo mergesort passando l'indice minimo e massimo del vettore.
    
    	cout << endl;
    
    	cout << "So, the sorted list (using MERGE SORT) will be :" << endl;
    
    	cout << endl << endl;

    	for(i=0; i<num; i++)
        	cout << a[i] << endl;

    	cout << endl << endl << endl << endl;
    	
	return 0;
}
