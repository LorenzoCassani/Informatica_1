INCS = `root-config --cflags`
LIBS = `root-config --libs`

CFLAGS = -Wall

all: compila clean

compila: Es_02.o lib.o
	g++ Es_02.o lib.o -o Es_02.x ${INCS} ${LIBS}

Es_02.o: Es_02.cpp
	g++ Es_02.cpp -c ${INCS}

lib.o: ../../lib.h ../../lib.cpp 
	g++ ../../lib.cpp -c ${INCS}

clean:
	rm *.o 
