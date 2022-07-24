all: compila clean

compila: Es_01.o lib.o
	g++ Es_01.o lib.o -o Es_01.x

Es_01.o: Es_01.cpp
	g++ Es_01.cpp -c

lib.o: ../../lib.h ../../lib.cpp 
	g++ ../../lib.cpp -c

clean:
	rm *.o
