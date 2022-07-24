INCS = `root-config --cflags`
LIBS = `root-config --libs`

CFLAGS = -Wall

all: compila clean

compila: main.o lib.o
	g++ main.o lib.o -o main ${INCS} ${LIBS}

main.o: lib.h main.cpp
	g++ main.cpp -c ${INCS}

lib.o: lib.h lib.cpp 
	g++ lib.cpp -c ${INCS}

esegui: main
	./main

clean:
	rm *.o
