/*
Cristian Eduardo Ríos Guarín - 20141020058
Diego Alejandro Henrnadez - 20141020271
*/
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>
/*Libreria maneja archivos*/
#include<fstream>
#include<conio.h>
using namespace std;
//------------------------- CALCULAR TIEMPO ----------------------------------

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter(){
    LARGE_INTEGER li;
    CounterStart = 0;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

	// Miscrosegundo -> 100000.0
    PCFreq = double(li.QuadPart)/100000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter(){
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
//------------------------------------------------------------------------------

void pedirDatos();
void mergeSort(int *,int,int);
void mergeList(int *,int,int,int,int);
void mostrarArreglo(int *,int);

int *a,n;


void pedirDatos1(int n){

	srand(time(NULL));
	a = new int [n];

	//Llenar desordenadamente	
	for(int i=0;i<n;i++){
		a[i]=rand()%100000+1000 ;
	}
	/*
	cout<<endl<<"Arreglo inicial "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
*/
}


int main(){	
	cout<<"ALGORITMO DE ORDENAMIENTO MEZCLA, (MERGESHORT)"<<endl<<endl<<endl;


	/*Variable de de entrada*/
	ofstream entrada ; 
	
	/*abriendo archcivo*/
	//ios::out -> si exite el archivo sobre escribir
	//ios::app -> no permeite borarr el archivo, lamcenara lo nuevo
	
	entrada.open("resultados.txt", ios::out | ios::app);  


	if(entrada.fail()){
		//fail() error
		printf("Error de lectura");
		getch();

	}else{
		
		n=0;
		for (n=20; n<1001; n+=20 ){		
		//	pedirDatos();
			pedirDatos1(n);
			//empieza conteo
			StartCounter();
			mergeSort(a,0,n-1);
			//asigna el valor de tiempo
			double tiempo = GetCounter(); 
			
			entrada<< n <<" - "<<tiempo<<endl; 
			cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms "<<endl;
			
			mostrarArreglo(a,n);
			cout<<endl;
		}
	}	
	getch();
	return 0;
}
//------------------------------------------------------------------------------

void pedirDatos(){
	cout<<"Ingrese la cantidad de datos del arreglo: ";cin>>n;
	//srand(time(NULL));
	a = new int [n];

	//Llenar desordenadamente	
	for(int i=0;i<n;i++){
		a[i]=rand()%100000+1000 ;
	}
	
	cout<<endl<<"Arreglo inicial "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
// Merge Sort --------------------------

void mergeSort(int *a,int first, int last){
	if(first<last){
		int middle = (first+last)/2;
		mergeSort(a,first,middle);
		mergeSort(a,middle+1,last);
		mergeList(a,first,middle,middle+1,last);
	}
}

void mergeList(int *a,int start1, int end1,int start2, int end2){
	int result[end2];
	int finalStart=start1;
	int finalEnd=end2;
	int indexC=1;

	while((start1<=end1)&&(start2<=end2)){
		if(a[start1]<a[start2]){
			result[indexC]=a[start1];
			start1 = start1+1;
		}else{
			result[indexC]=a[start2];
			start2 = start2+1;
		}
		indexC=indexC+1;
	}
	if(start1<=end1){
		for(int i=start1;i<=end1;i++){
			result[indexC]=a[i];
			indexC=indexC+1;
		}
	}else{
		for(int i=start2;i<=end2;i++){
			result[indexC]=a[i];
			indexC=indexC+1;
		}
	}
	
	indexC=1;
	for(int i=finalStart;i<=finalEnd;i++){
		a[i]=result[indexC];
		indexC=indexC+1;
	}
}

// Imprimir arreglo Ordenado --------------------
void mostrarArreglo(int *a, int n){
	cout<<endl<<endl<<"Arreglo Ordenado (Ascendente) "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
