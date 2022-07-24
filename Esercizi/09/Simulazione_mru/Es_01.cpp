#include "../../lib.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TF1.h"

#define N 100

using namespace std;



int main(){

	//Esercizio 2: GENERAZIONE MISURE

	const float mean=0;
	const float stdDev=0.4;

	float v1;
	float v2;

	const float v=3.2;
	const float x0=2.1;
	const float dt=0.05;

	ofstream out1;
	ofstream out2;

	out1.open("misure.dat");
	out2.open("discrepanze.dat");

	initRand();

	cout << endl << "SIMULAZIONE: Moto Rettilineo Uniforme" << endl;
	cout << endl << "Legge del moto: x(t) = v*t+x0" << endl;
	cout << endl << endl << "PARAMETRI FISSATI:" << endl;
	cout << endl << "v = " << v << " m/s\t" << "x0 = " << x0 << " m" << endl;
	cout << endl << "dt = " << dt << " s\t" << "nPassi = " << N << endl;
	
	//ALLOCAZIONE DINAMICA ARRAY
	float* tmp=new float[N];
	float* posx=new float[N];
	float* err=new float[N];
	float* posy=new float[N];

	//CARICAMENTO ARRAY
	for(int i=0; i<N; i++)
		tmp[i]=dt*i;

	for(int i=0; i<N; i++)
		posx[i]=v*tmp[i]+x0;

	err=generaRandGauss(mean,stdDev,N);

	for(int i=0; i<N; ++i)
		posy[i]=posx[i]+err[i];

	//SCRITTURA SU FILE
	for(int i=0; i<N; ++i)
		out1 << tmp[i] << "\t" << posy[i] << endl;

	for(int i=0; i<N; ++i)
		out2 << tmp[i] << "\t" << err[i] << endl;

	out1.close();
	out2.close();

	cout << endl << endl << "Le coppie tempo-posizione sono state salvate nel file: misure.dat" << endl;
	cout << "Quelle tempo-discrepanze posizione sono state salvate nel file: discrepanze.dat" << endl;

	//ROOT
	TApplication app("app",0,0);

	//Scatterplot
	TCanvas canvas1;
	TGraph grafico;

	for(int i=0; i<N; ++i)
		grafico.SetPoint(i,tmp[i],posy[i]);

	canvas1.cd();
	grafico.GetXaxis()->SetTitle("t");
	grafico.GetYaxis()->SetTitle("x(t)");
	grafico.Draw("A*");

	//Esercizio 3: ANALISI DATI DELL'ESPERIMENTO

	cout << endl << endl << "ANALISI DATI:" << endl;

	cout << endl << "-FIT LINEARE:" << endl;

	//Fit
	grafico.Fit("pol1"); //Stampo a terminale una tabella predefinita di fit per una funzione polinomiale di grado 1

	TF1* funzione = grafico.GetFunction("pol1"); //Accedo ai parametri del fit lineare
    	float x0_fit = funzione->GetParameter(0);
    	float v_fit = funzione->GetParameter(1);

	cout << endl << "p0 = q (quota) = x0" << "\t" << "x0 (ideale) = " << x0 << endl;
	cout << endl << "p1 = m (pendenza) = v" << "\t" << " v (ideale) = " << v << endl;

	float* posy_fit=new float[N];
	float* err_fit=new float[N];

	for(int i=0; i<N; i++)
		posy_fit[i]=v_fit*tmp[i]+x0_fit;
	
	for(int i=0; i<N; i++)
		err_fit[i]=posx[i]-posy_fit[i];

	//Istogramma

	float min = err_fit[trovaMin(err_fit,N)];
	float max = err_fit[trovaMax(err_fit,N)];

	float scotts = 3.5f*stdDev/pow((float)N,1.f/3.f);
    	float nbins = ceil((max-min)/scotts);

	TCanvas canvas2;
	TH1F* istogramma = new TH1F("Histo", "Error Histogram", nbins, min-1e-3, max+1e-3);

	for(int i=0; i<N; i++)
        	istogramma->Fill(err_fit[i]);

	canvas2.cd();
	istogramma->Draw();
	
	//DEALLOCAZIONE ARRAY
	delete[] tmp;
	delete[] posx;
	delete[] err;
	delete[] posy;
	delete[] posy_fit;
	delete[] err_fit;

	cout << endl << "FINE SIMULAZIONE (Ctrl+c per uscire dal programma)" << endl;

	app.Run();

	return 0;
}
