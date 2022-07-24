#Definisco delle variabili
INCS = `root-config --cflags`
LIBS = `root-config --libs`

#FLAGS (opzioni) del compilatore

CFLAGS = -Wall

all: monteCarlo.x provaFit.x provaHisto.x

monteCarlo.x: monteCarlo.cpp
	g++ monteCarlo.cpp -o monteCarlo.x ${INCS} ${LIBS}

provaFit.x: provaFit.cpp
	g++ provaFit.cpp -o provaFit.x ${INCS} ${LIBS}

provaHisto.x: provaHisto.cpp
	g++ provaHisto.cpp -o provaHisto.x ${INCS} ${LIBS}

#Sostituisco `root-config --cflags` e `root-config --libs` usando le due variabili definite sopra

