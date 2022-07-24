#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define INIT_DIM  20 //Dimensione iniziale array
#define INCR_DIM  10 //Incremento dimensione array

/*************************************************STRUCT*********************************************************************************************/

struct palla{
	char colore;
    	int cod;
    	float pos[2];
    	float massa;
    	double raggio;
};

struct myArrayInt{
	int size;
    	int used;
    	int *raw;
};

/*************************************************CLASSI*********************************************************************************************/

class myArrayFloat{

	public: //Interfaccia

    	//Campi

	//Metodi
    	void initialize(); //Inizializza i campi a 0,0,NULL rispettivamente

    	void initialize(int); //Crea l’array in memoria e aggiorna size consistentemente

    	void initialize(char []); //Carica il vettore da file

	float at(int); //Restituisce un elemento dell’array

    	int insert(float,int); //Aggiunge un elemento all’array nella posizione indicata (senza lasciare buchi)

    	int remove(int); //Elimina il dato in una certa posizione e ricompatta l’array

	void sort(); //ordina l’array

    	private:

	//Campi
    	int size;
    	int used;
    	float* raw;

	//Metodi
    	int resize(int); //ridimensiona l’array
};

class elemInt{
	
	public:

	int val;
    	elemInt *next;

    	elemInt(); //Assegna NULL al campo next;
    	elemInt(int); //Come il precedente piu` assegnamento del valore intero a val
};

class stackInt{
    
	public:

	//Metodi
	bool isEmpty();
        void push(int);
        int pop();
        int top();

        stackInt(); //Costruttore
        ~stackInt(); //Distruttore

	private:

	//Campi
    	elemInt *head;
    	elemInt *tail;
};


/*************************************************FUNZIONI*******************************************************************************************/

//Chiede all'utente quanti valori caricare in un array, controlla e carica
//Restituisce il numero di valori caricati
//Primo parametro: array
//Secondo parametro: dimensione massima
int caricaDati(float [],int);

//Calcola la media di un campione di dati contenuti in un array
//Primo parametro: array
//Secondo parametro: dimensione dell'array
float media(float [],int);

//Calcola la varianza di un campione di dati contenuti in un array
//Primo parametro: array
//Secondo parametro: dimensione dell'array
float varCamp(float [],int);

//Stampa i valori contenuti in un array
//Primo parametro: array
//Secondo parametro: dimensione dell'array
void stampa(float [],int);

//Restituisce la posizione del valore minimo contenuto in un array
//Primo parametro: array
//Secondo parametro: dimensione dell'array
int trovaMin(float [],int);

//Restituisce la posizione del valore massimo contenuto in un array
//Primo parametro: array
//Secondo parametro: dimensione dell'array
int trovaMax(float [],int);

//Scambia due elementi di un array
//primo parametro: array
//secondo parametro: posizione del primo elemento da scambiare
//terzo parametro: posizione dell'altro elemento da scambiare
void swapArrayFloat(float [],int,int);

//Divisione Euclidea: restituisce un array contenente il quoziente in posizione 0 ed il resto in posizione 1
//Primo parametro: dividendo
//Secondo parametro: divisore
//Terzo parametro: array in cui immagazzinare quoziente e resto
void divEucl(int,int,int []);

//Genera numeri "a caso" in un intervallo
//Primo parametro: estremo sinistro dell'intervallo
//Secondo parametro: estremo destro dell'intervallo
float randUnif(float,float);

//Selection Sort: ordina in ordine crescente gli elementi di un array
//Primo parametro: array
//Secondo parametro: dimensione dell'array
void selectionSort(float [],int);

//Scambia il contenuto di due variabili
//Primo parametro: puntatore alla prima variabile
//Secondo parametro: puntatore alla seconda variabile
void swap(float*,float*);

//Carica un dato di tipo struct con dei dati contenuti in un file di testo
//Primo parametro: nome del file da cui prendere i dati
//Secondo parametro: puntatore al dato di tipo struct nel quale caricare i dati
void caricaStructPalla(char [],palla*);

//Restituisce l'elemento in posizione (i,j) di una matrice streamlined
//Primo parametro: matrice streamlined
//Secondo parametro: indice riga dell'elemento
//Terzo parametro: indice colonna dell'elemento
//Quarto parametro: numero righe matrice
//Quinto parametro: numero colonne matrice
float at(float [],int,int,int,int);

//Inizializza srand
void initRand();

//Genera numeri casuali all'interno di un intervallo in modo uniforme
//Primo parametro: estremo sinistro dell'intervallo
//Secondo parametro: estremo destro dell'intervallo
float generaRandFloat(float,float);

//Restituisce una misura di pi
//Primo parametro: numero di punti utilizzati per effettuare una misura
//Secondo parametro: lato l del quadrato centrato nell’origine e circoscritto ad una circonferenza di raggio l/2
float misuraPi(int,float);

//Restituisce l'indirizzo dell'array caricato con delle misure di pi
//Primo parametro: numero di punti utilizzati per effettuare una misura
//Secondo parametro: lato l del quadrato centrato nell’origine e circoscritto ad una circonferenza di raggio l/2
//Terzo parametro: numero di misure di pi con cui caricare l'array
float* esperimentoPi(int,float,int);

//Genera due numeri casuali estratti da una distribuzione gaussiana di media mean e deviazione standard stdDev e li immagazzina in due variabili
//Primo parametro: media della gaussiana
//Secondo parametro: deviazione standard della gaussiana
//Terzo parametro: variabile 1
//Quarto parametro: variabile 2
void boxMuller(float,float,float*,float*);

//Restituisce l'indirizzo dell'array caricato con dei numeri casuali estratti da una distribuzione gaussiana di media mean e deviazione standard stdDev
//Primo parametro: media della gaussiana
//Secondo parametro: deviazione standard della gaussiana
//Terzo parametro: numero di valori con cui caricare l'array
float* generaRandGauss(float,float,int);

//Ridimensiona un array di interi da una vecchia dimensione ad una nuova dimensione
//Primo parametro: puntatore all'array di interi da ridimensionare
//Secondo parametro: vecchia dimensione
//Terzo parametro: nuova dimensione
void resize(int**,int,int);

//Stampa a terminale una variabile di tipo struct myArrayInt
//Primo parametro: struct myArrayInt da stampare
void print(myArrayInt);

//Restituisce una variabile di tipo struct myArrayInt caricata con dati contenuti in un file
//Primo parametro: nome del file
myArrayInt caricaArrayFile(char []);

//Merge (utilizzata da Merge Sort)
//Primo parametro: array
//Secondo parametro: indice piu` piccolo dell'array
//Terzo parametro: mezzo dell'array da fondere
//Quarto parametro: indice piu` grande dell'array
void merge(int [],int,int,int);

//Merge Sort
//Primo parametro: array da fondere
//Secondo parametro: indice piu` piccolo dell'array da fondere
//Terzo parametro: indice piu` grande dell'array da fondere
void mergeSort(int [],int,int);

//Binary Search (utilizzata da findCount)
//Primo parametro: array
//Secondo parametro: indice piu` piccolo dell'array
//Terzo parametro: indice piu` grande dell'array
//Quarto parametro: valore da cercare
int findBin(int*,int,int,int);

//Cerca un valore in un array, se è presente conta quante volte e stampa le posizioni nell'array a terminale
//Primo parametro: array
//Secondo parametro: dimensione dell'array
//Terzo parametro: dimensione utilizzata dell'array
void findCount(int*,int,int);
