#include "../../lib.h"

//Librerie root
#include "TApplication.h" //Runtime environment
#include "TCanvas.h" //Tele su cui disegnare
#include "TGraph.h" //ScatterPlot
#include "TAxis.h"

#define NMISURE 50

using namespace std;

int main(){

	float l=2;

	TApplication app("app",0,0);
	TCanvas canvasMean;
	TCanvas canvasStdDev;
	TGraph graficoMean;
	TGraph graficoStdDev;
	
	initRand();

	int j=0; //Contatore punti in R2
	for(int i=50; i<=1000; i+=50){

		float* arr=esperimentoPi(i,l,NMISURE);

		graficoMean.SetPoint(j,i,media(arr,NMISURE));
		graficoStdDev.SetPoint(j,i,sqrt(varCamp(arr,NMISURE)));

		++j;		

		delete[] arr;
	}

	canvasMean.cd();
	graficoMean.GetXaxis()->SetTitle("n");
	graficoMean.GetYaxis()->SetTitle("mean(n)");
	graficoMean.Draw("A*");

	canvasStdDev.cd();
	graficoStdDev.GetXaxis()->SetTitle("n");
	graficoStdDev.GetYaxis()->SetTitle("stdDev(n)");
	graficoStdDev.Draw("A*");

	app.Run(0);

	return 0;
}
