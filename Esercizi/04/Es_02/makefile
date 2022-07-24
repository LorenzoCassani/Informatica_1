all: compila clean

compila: Es_02.o lib.o
	g++ Es_02.o lib.o -o Es_02.x

Es_02.o: Es_02.cpp
	g++ Es_02.cpp -c

lib.o: ../../lib.h ../../lib.cpp 
	g++ ../../lib.cpp -c

clean:
	rm *.o 
