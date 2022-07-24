all: compila clean

compila: Es_03.o lib.o
	g++ Es_03.o lib.o -o Es_03.x

Es_03.o: Es_03.cpp
	g++ Es_03.cpp -c

lib.o: ../../lib.h ../../lib.cpp 
	g++ ../../lib.cpp -c

clean:
	rm *.o 
