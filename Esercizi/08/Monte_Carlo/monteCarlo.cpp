#include <iostream>
#include <cstdlib>
#include <ctime>

//Librerie root
#include "TCanvas.h" //Tele su cui disegnare
#include "TApplication.h" //Runtime environment
#include "TGraph.h" //ScatterPlot
#include "TH1F.h" //Istogrammi
#include "TF1.h" //Funzioni a una variabile
#include "TEllipse.h"

using namespace std;

int main(){

	float* vett_x;
    	float* vett_y;

    	TApplication app("Applicazione",0,0);
	
    	const int dim = 100;

    	vett_x = new float[dim];
    	vett_y = new float[dim];

    	for(int i=0; i<dim; i++){
        	vett_x[i] = 2*((float) rand()/RAND_MAX)-1;
        	vett_y[i] = 2*((float) rand()/RAND_MAX)-1;
    	}

    	TCanvas* tela = new TCanvas("prova","MONTE CARLO",600,600);
    	tela->DrawFrame(-2,-2,2,2);
 
    	TEllipse *cerchio = new TEllipse(0,0,1,1);
    	cerchio->SetFillColor(2);
    	(*cerchio).SetFillColor(2);
    	cerchio->Draw();
    
    	//Preparo scatter plot (non disegno)
    	TGraph* grafo = new TGraph(dim,vett_x,vett_y);
    	grafo->Draw("*");

    	TF1* funzione = new TF1("funzione1","sin(10*x)+x",-10,10);
    	funzione->SetLineColor(3);

    	//Se ometto "same" il grafico della funzione cancella quanto disegnato fino ad ora
    	funzione->Draw("same");
       	app.Run(1);

    	return 0;
}
