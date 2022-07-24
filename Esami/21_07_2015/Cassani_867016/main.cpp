#include "lib.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TF1.h"

using namespace std;

int main(){

	TApplication app("app",0,0);

	//PRIMA PARTE

	Poligono* poligoni;
	unsigned int npoligoni=0;

	ofstream out;
	out.open("risultati.dat");
	if(out.fail()){
		cerr << "Errore apertura file ''risultati.dat'', interrompo il programma." << endl;
		return 1;
	}

	CaricaDaFile("poligoni.dat", poligoni, npoligoni);

	cout << "Numero di poligoni: " << npoligoni << endl;
	out << "Numero di poligoni: " << npoligoni << endl;

	for(unsigned int i=0; i<npoligoni; ++i){
		if(Intrecciato(poligoni[i])){
			cout << "Il poligono n'" << i+1 << " è intrecciato." << endl;
			out << "Il poligono n'" << i+1 << " è intrecciato." << endl;
		}
	}

	//SECONDA PARTE

	unsigned int npunti=0;
	PuntoR2* punti;
	GetPunti(poligoni,npoligoni,punti,npunti);

	for(unsigned int i=0; i<npoligoni; ++i) delete[] poligoni[i].vertici;
	delete[] poligoni;

	SelsortCrescente(punti,npunti);

	cout << "Ascissa minima: x = " << punti[0].x << endl;
	out << "Ascissa minima: x = " << punti[0].x << endl;

	cout << "Ascissa massima: x = " << punti[npunti-1].x << endl;
	out << "Ascissa massima: x = " << punti[npunti-1].x << endl;

	out.close();


	TCanvas tela("Istogramma","Strisce verticali");

	TH1F histo("","",10,punti[0].x-0.5,punti[npunti-1].x+0.5);

	for(unsigned int i=0; i<npunti; ++i) histo.Fill(punti[i].x);

	delete[] punti;


	tela.cd();
	histo.Draw();
	app.Run();

	return 0;
}
