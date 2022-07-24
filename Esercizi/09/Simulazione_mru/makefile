INCS = `root-config --cflags`
LIBS = `root-config --libs`

CFLAGS = -Wall

all: compila clean

compila: Es_01.o lib.o
	g++ Es_01.o lib.o -o Es_01.x ${INCS} ${LIBS}

Es_01.o: Es_01.cpp
	g++ Es_01.cpp -c ${INCS}

lib.o: ../../lib.h ../../lib.cpp 
	g++ ../../lib.cpp -c ${INCS}

clean:
	rm *.o
