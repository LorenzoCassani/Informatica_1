#include "lib.h" 

using namespace std;

/*************************************************METODI CLASSI**************************************************************************************/

//////////////////////////////////////////////////myArrayFloat////////////////////////////////////////////////////////////////////////////////////////

void myArrayFloat::initialize(){
    
	size=0;
    	used=0;
    	raw=NULL;
}

void myArrayFloat::initialize(int dim){
    
	size=dim;
    	used=0;
    	raw=new float[dim];
}

void myArrayFloat::initialize(char nomefile[]){

	float appo;
	
    	size=0;
    	used=0;
    	raw=NULL;

	ifstream in;
    	in.open(nomefile);

    	if(in.fail()){
        	cout << endl << "Problema apertura file in caricaArrayFile!" << endl;
        	return;
    	}

    	size=INIT_DIM;
    	used=0;
    	raw=new float[size];
    
    	in >> appo;
    	while(!in.eof()){
        	if(used >= size){
			resize(size+INCR_DIM);
        	}
        	raw[used++]=appo;
        	in >> appo;
    	}
    	in.close();
	
	//OPZIONALE: riduco la dimensione dell'array a quella utilizzata (size=used)
	//resize(used);
}

float myArrayFloat::at(int pos){

	return raw[pos];
}

int myArrayFloat::insert(float num, int pos){
    
	int check;

    	if(used==size){
        	check=resize(size+INCR_DIM);
        	if(check < 0){
            		cout << endl << "Insert: problem!!! Element not inserted" << endl;
            		return -1;
        	}
    	}

    	//Se non ci sono problemi

    	//1-Sposto tutti gli elementi dopo la posizione in cui voglio inserire in avanti di uno
    	for(int i=used; i>pos; i--)
        	raw[i]=raw[i-1];

    	//2-Inserisco l'elemento nuovo
    	raw[pos]=num;
    	used++;
}

int myArrayFloat::remove(int pos){
        
	if(pos<0 or pos>=used){
        	cout << endl << "Remove: posizione fuori range!" << endl;
        	return -1;
    	}

    	for(int i=pos; i<used-1; i++)
        	raw[i]=raw[i+1];
		raw[used-1]=0;
    
    	used--;
    	return 0;
}

int myArrayFloat::resize(int newDim){
    
    	int toCopy;
    	float* appo=NULL;

    	appo=new float[newDim];

    	//Problema allocazione
    	if(appo==NULL){
        	cout << endl << "Problema allocazione" << endl;
        	return -1;
    	}
    
    	//Controllo se è un resize a crescere o a ridurre
    	toCopy=(newDim>size?size:newDim);

    	//Copio gli elementi da copiare
    	for(int i=0; i<toCopy; i++)
        	appo[i]=raw[i];

    	delete[] raw;
    
    	raw=appo;
    	size=newDim;
    
    	return newDim;
}

void myArrayFloat::sort(){

	for(int j=0; j<used-1; j++){
		int iMin=j;
        	for(int i=j; i<used; i++){
        		if(raw[i]<raw[iMin]){
        	    		iMin=i;
        		}
    		}
    		if(iMin!=j){
        		swap(raw[j],raw[iMin]);//"swap" è una funzione propria del namespace std
    		}
	}
}

//////////////////////////////////////////////////elemInt/////////////////////////////////////////////////////////////////////////////////////////////

elemInt::elemInt(){

	next = NULL;
}

elemInt::elemInt(int v){

	next=NULL;
	val=v;
}

//////////////////////////////////////////////////stackInt////////////////////////////////////////////////////////////////////////////////////////////

bool stackInt::isEmpty(){

    	if(tail == NULL)
        	return true;

    	else 
        	return false;
}

void stackInt::push(int el){

    	//La cima dello stack è il primo elemento della lista
    	elemInt *nuovo;
    	nuovo=new elemInt(el);

    	if(isEmpty()) //Solo se l'elemento inserito e` il primo
        	tail = nuovo;

    	nuovo->next = head;
    	head = nuovo;
    	cout << endl << "Push: head = " << head << endl;    
}

int stackInt::pop(){

    	//Rimuoviamo in testa alla lista
    	elemInt appo;
    	if(isEmpty()){
        	cout << endl << "Stack vuoto" << endl;
        	return 0;
    	}
    
    	appo= *head; //Copio il primo elemento della lista in appo
    	delete head; //Elimino il primo elemento della lista
    	head=appo.next;
    	//Non resetto il campo next di appo per debug...
    	//ma volendo essere puliti...

    	//Se l'elemento che stiamo cancellando e` l'ultimo rimasto nello stack
    	if (head == NULL)
        	tail== NULL;

    	return appo.val;    
}

int stackInt::top(){

    	//Restituisce il primo elemento della lista
    	return head->val;
}
        
//Costruttore: senza argomenti, per inizializzare
stackInt::stackInt(){

    	head = NULL;
    	tail = NULL;
}

//Distruttore: fa pulizia
stackInt::~stackInt(){

    	while(head !=NULL){
    		cout << endl <<"Distruggo!" << endl;
    		cout << endl <<"Valore del cancellato: " << head->val << endl;
   		//while(!isEmpty())
        	pop();
    	}
}

/*************************************************FUNZIONI*******************************************************************************************/

//////////////////////////////////////////////////FUNZIONI ARRAY//////////////////////////////////////////////////////////////////////////////////////

int caricaDati(float d[], int dimMax){

	int num;
    
	do{
    		cout << endl <<"Quanti dati? (Max: " << dimMax <<")" <<endl;
    		cin >>num;
    	}while(num > dimMax || num <=0);

    	for(int i=0; i<num; i++){
        	cout <<"Dato: " ;
        	cin >>d[i];
    	}
    
    	return num;
}

float media(float d[], int dim){
	float appo=0;
	for(int i=0; i<dim; i++){
		appo+=d[i];
	}
	
	return appo/dim;
}

float varCamp(float d[], int dim){

	float appo2=0;
	for(int i=0; i<dim; i++){
		appo2+=d[i]*d[i];
	}

	return appo2/dim-pow(media(d,dim),2);
}

void stampa(float d[], int l){

	for(int i=0; i<l; i++)
        	cout << d[i] <<endl;
}

int trovaMin(float v[], int size){

	float min;
	int posMin;

	min = v[0];
	posMin = 0;

	for(int i=1; i<size; i++){
		if(v[i]<min){
			min = v[i];	
			posMin=i;
		}
	}

	return posMin;
}

int trovaMax(float v[], int size){

	float max;
	int posMax;

	max = v[0];
	posMax = 0;

	for(int i=1; i<size; i++){

		if(v[i]>max){
			max = v[i];	
			posMax=i;
		}
	}

	return posMax;
} 

void swapArrayFloat(float v[], int pos1, int pos2){

	//Variabile di appoggio
    	float appo;
    	appo = v[pos1];
    	v[pos1] = v[pos2];
    	v[pos2] = appo;

    	//Non restituisco nulla perche' il tipo di ritorno e` void
}

//////////////////////////////////////////////////DIVISIONE EUCLIDEA//////////////////////////////////////////////////////////////////////////////////

void divEucl(int a, int b, int res[2]){

	int ratio, mod;

	cout << endl << "Inserire a: " << endl;
    	cin >> a;
	cout << endl << "Inserire b: " << endl;
    	cin >> b;

	if(b==0){
    		cerr << endl << "Il divisore non può essere 0!" << endl;
		res[1]=-1;
		return;
	}
	else{
    		if(a<0){
        		if(b<0){
				mod=a%b;				
				if(mod!=0){            			
					ratio=-a/-b +1;
					mod=mod -b;
				}
				else{
					ratio=a/b;
				}
        		}
        		else{
            			ratio=a/b -1;
            			mod=a%b +b;
        		}
   		}
    		else{
        		ratio=a/b;
        		mod=a%b;
    		}
	res[0]=ratio;
	res[1]=mod;
	}
}

//////////////////////////////////////////////////ERRORE UNIFORME INTERVALLO [a,b]////////////////////////////////////////////////////////////////////

//NOTA: ricordarsi di inizializzare srand prima di utilizzare randUnif (e qualsiasi altra funzione "random")

float randUnif(float a, float b){

	float appo=((float) rand())/RAND_MAX;

    	return appo*(b-a)+a;
}

//////////////////////////////////////////////////SELECTION SORT//////////////////////////////////////////////////////////////////////////////////////

void selectionSort(float v[], int size){

	for(int j=0; j<size-1; j++){
		int iMin=j;
        	for(int i=j; i<size; i++){
        		if(v[i]<v[iMin]){
        	    		iMin=i;
        		}
    		}
    		if(iMin!=j){
        		swap(v[j],v[iMin]);//"swap" è una funzione propria del namespace std
    		}
	}
}

//////////////////////////////////////////////////SWAP VARIABILI//////////////////////////////////////////////////////////////////////////////////////

void swap(float* p1, float* p2){

	float appo;
	appo=*p1;
      	*p1=*p2;
       	*p2=appo;
}

//////////////////////////////////////////////////STRUCT PALLA////////////////////////////////////////////////////////////////////////////////////////

void caricaStructPalla(char nomefile[], palla* ppalla){

	ifstream in;
	in.open(nomefile);

	if(in.fail()) //Se si verifica un errore nell'apertura del file, esci e non allocare memoria
        	return;

    	in >> (*ppalla).colore;
    	in >> (*ppalla).cod;
    	in >> (*ppalla).pos[0] >> (*ppalla).pos[1];
    	in >> (*ppalla).massa;
    	in >> (*ppalla).raggio;

	in.close();
}

//////////////////////////////////////////////////MATRICE STREAMLINED/////////////////////////////////////////////////////////////////////////////////

float at(float matr[], int i, int j, int nRows, int nCols){
	
	if(i>nRows-1 or j>nCols-1) 
		return 0;

	return matr[i+i*nRows+j];
}

//////////////////////////////////////////////////INIZIALIZZA RAND////////////////////////////////////////////////////////////////////////////////////

void initRand(){

	srand(time(NULL));
}

//////////////////////////////////////////////////RUMORE UNIFORME/////////////////////////////////////////////////////////////////////////////////////

float generaRandFloat(float a, float b){

	float appo=((float) rand())/RAND_MAX;

    	return appo*(b-a)+a;
}

//////////////////////////////////////////////////ESPERIMENTO PI//////////////////////////////////////////////////////////////////////////////////////

float misuraPi(int nPunti, float l){

	float a=0; //Estremo sx dell'intervallo
	float b=l/2; //Estremo dx dell'intervallo

	int cerchio=0;

	for(int i=0; i<nPunti; i++){

		float x=generaRandFloat(a,b); //Coordinata x del punto
		float y=generaRandFloat(a,b); //Coordinata y del punto

		//Se il punto si trova dentro l'1/4 del cerchio considerato...
		//(se la distanza del punto dall'origine è <= l/2, dove l/2 è il valore del raggio della circonferenza inscritta)
		if(sqrt(x*x+y*y) <= l/2)
			cerchio++; //Incremento il contatore
		}

	//pi=area cerchio/area quadrato*4
	return (float)cerchio/nPunti*4; //Converto a float
}

float* esperimentoPi(int nPunti, float l, int nMisure){

	float* arr=new float[nMisure]; //Alloco dinamicamente l'array

	for(int i=0; i<nMisure; ++i) //Carico l'array con nMisure misure di pi
		arr[i]=misuraPi(nPunti,l);

	return arr;
}

//////////////////////////////////////////////////RUMORE GAUSSIANO////////////////////////////////////////////////////////////////////////////////////

void boxMuller(float mean, float stdDev, float* v1, float* v2){

	float u1=randUnif(0,1); 
	float u2=randUnif(0,1);

	float z0=sqrt(-2*log(u1))*cos(2*M_PI*u2);	
    	float z1=sqrt(-2*log(u1))*sin(2*M_PI*u2);

	*v1=z0*stdDev+mean;
	*v2=z1*stdDev+mean;
}

float* generaRandGauss(float mean, float stdDev, int quanti){

	float* arr=new float[quanti];

    	float appo;

    	for(int i=0; i<quanti/2; i++)
        	boxMuller(mean,stdDev,&arr[2*i],&arr[2*i+1]);

    	if(quanti%2==1)
        	boxMuller(mean,stdDev,&arr[quanti-1],&appo);

	return arr;
}

//////////////////////////////////////////////////RESIZE//////////////////////////////////////////////////////////////////////////////////////////////

void resize(int **pwho, int oldDim, int newDim){

    	int *newarr;

    	if(oldDim>newDim){
        	cout << endl << "Problema resize! oldDim > newDim" << endl;
        	return;
    	}

    	//Creo vettore nuovo piu` grande
    	newarr = new int[newDim];

    	//Riverso dati nel nuovo vettore
    	for(int i=0; i<oldDim; i++){
        	newarr[i]= (*pwho)[i]; //ATTENZIONE: *pwho[i] sbagliato per priorita` operatori
    	}

    	delete[] *pwho;
    	*pwho = newarr;
    
    	return;
}

//////////////////////////////////////////////////PRINT///////////////////////////////////////////////////////////////////////////////////////////////

void print(myArrayInt toprint){

	cout << endl << "L'array ha dimensione: " << toprint.size << endl;
    	cout << endl << "L'array ha " << toprint.used << " elementi caricati" << endl;
    	cout << endl << "Elementi: " << endl;
    	for(int i=0; i<toprint.used; i++)
        	cout << endl << toprint.raw[i];
    		cout << endl;
}

//////////////////////////////////////////////////CARICA ARRAY FILE///////////////////////////////////////////////////////////////////////////////////

myArrayInt caricaArrayFile(char nomefile[]){

	int appo;
	
    	myArrayInt pippo;

    	pippo.size=0;
    	pippo.used=0;
    	pippo.raw=NULL;

	ifstream in;
    	in.open(nomefile);

    	if(in.fail()){
        	cout << endl << "Problema apertura file in caricaArrayFile!" << endl;
        	return pippo;
    	}

    	pippo.size=INIT_DIM;
    	pippo.used=0;
    	pippo.raw=new int[pippo.size];
    
    	in >> appo;
    	while(!in.eof()){
        	if(pippo.used >= pippo.size){
            		resize(&pippo.raw,pippo.size,pippo.size+INCR_DIM);
            		pippo.size+=INCR_DIM;
        	}
        	pippo.raw[pippo.used++]=appo;
        	in >> appo;
    	}
    	in.close();

    	return pippo;
}

//////////////////////////////////////////////////MERGE SORT//////////////////////////////////////////////////////////////////////////////////////////

void merge(int a[],int low, int mid, int high){
//low: indice piu` piccolo dell'array da fondere
//mid: mezzo dell'array da fondere
//high: indice piu` grande dell'array da fondere

    	int h,i,j,k;

    	int* b=new int[high+1]; //Abbiamo bisogno di un array di appoggio dove copiare i dati

    	h=low; //Indice libero per scandire array di sinistra
    	i=low; //Indica la prima posizione libera dell'array in cui stiamo copiando i dati
    	j=mid+1; //Indice libero per scandire array di destra

    	while((h<=mid)&&(j<=high)){ //Mentre non hai esaurito uno dei due sottoarray
        	if(a[h]<=a[j]){
            		b[i]=a[h];
            		h++; //Avanza di uno con l'indice libero dell'array di sinistra
        	}
        	else{
            		b[i]=a[j];
            		j++; //Avanza di uno con l'indice libero dell'array di destra
        	}
        	i++; //
    	}

    	if(h>mid){ //Se hai esaurito il sottoarray di sinistra, riversa in b quanto rimane del sottoarray di destra
        	for(k=j;k<=high;k++){
            		b[i]=a[k];
            		i++;
        	}
    	}
    	else{
        	for(k=h;k<=mid;k++){ //Se hai esaurito il sottoarray di destra, riversa in b quanto rimane del sottoarray di sinistra
            		b[i]=a[k];
            		i++;
        	}
    	}
    	for(k=low;k<=high;k++)
		a[k]=b[k]; //Ricopia in a l'array ordinato b

	delete[] b;
}

void mergeSort(int a[],int low,int high){
	
	int mid;
    	if(low<high){
        	mid=low+(high-low)/2; //Questo serve ad evitare l'overflow quando low e/o high sono troppo grandi
        	mergeSort(a,low,mid);
        	mergeSort(a,mid+1,high);
        	merge(a,low,mid,high);
    	}
}

//////////////////////////////////////////////////BINARY SEARCH///////////////////////////////////////////////////////////////////////////////////////

//NOTA: L'algoritmo di binary search va utilizzato su un array già ordinato!
//(se l'array è disordinato findCount non conta correttamente il numero di occorrenze del valore int)

int findBin(int arr[], int low, int high, int value){

	int mid;

     	if(high < low)
        	return -1; //Not found

     	mid=low+((high-low)/2);
 
     	if(arr[mid] > value)
        	return findBin(arr,low,mid-1,value);

     	else if(arr[mid] < value)
         	return findBin(arr,mid+1,high,value);

     	else
         	return mid; //Found
}

void findCount(int arr[], int dim, int used){

	int low=0;
	int high=used-1;
	int value;

	int appo;
	int conta=1;
	int primo;

	cout << endl << "Valore (int) da cercare nell'array: ";
	cin >> value;

	appo = findBin(arr,low,high,value);

	if(appo==-1)
		cout << endl << "Il valore non è presente nell'array!" << endl;

	else{
		cout << endl << "Il valore è presente nell'array!" << endl;

		primo = appo;

		while(arr[appo]==arr[appo+1]){

			appo++;
			conta++;
		}

		cout << endl << "Numero occorrenze: " << conta << endl;

		cout << endl << "Posizione delle occorrenze del valore nell'array: da [" << primo << "] a [" << appo << "]" << endl;
	}
}
