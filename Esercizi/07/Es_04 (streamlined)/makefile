all: compila clean

compila: Es_04.o lib.o
	g++ Es_04.o lib.o -o Es_04.x

Es_04.o: Es_04.cpp
	g++ Es_04.cpp -c

lib.o: ../../lib.h ../../lib.cpp 
	g++ ../../lib.cpp -c

clean:
	rm *.o
