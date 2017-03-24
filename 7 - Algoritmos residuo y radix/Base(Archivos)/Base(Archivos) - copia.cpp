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
int max(int *,int);
void orden1(int *,int,int);
void bases(int *,int);
void mostrarArreglo(int *,int);

int *a,n,numD;

int main(){	
	cout<<"ALGORITMO DE ORDENAMIENTO POR INTERCAMBIO DE RESIDUOS"<<endl<<endl<<endl;


	/*Variable de de entrada*/
	ofstream entrada ; 
	
	/*abriendo archcivo*/
	//ios::out -> si exite el archivo sobre escribir
	//ios::app -> no permeite borarr el archivo, lamcenara lo nuevo
	
	entrada.open("resulados.txt", ios::out | ios::app);  


	if(entrada.fail()){
		//fail() error
		printf("Error de lectura");
		getch();

	}else{
		
		pedirDatos();
		//empieza conteo
		StartCounter();
		bases(a,n);
		//asigna el valor de tiempo
		double tiempo = GetCounter(); 
		
		entrada<< n <<" -> (numDigitos) "<<numD<<" -> (tiempo) "<<tiempo<<endl; 
		cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms "<<endl;
		
		mostrarArreglo(a,n);
		cout<<endl;
	}	
	getch();
	return 0;
}
//------------------------------------------------------------------------------

void pedirDatos(){
	cout<<"Ingrese la cantidad de datos del arreglo: ";cin>>n;
	cout<<"Ingrese la cantidad de digitos (4/6/8): ";cin>>numD;
	srand(time(NULL));
	a = new int [n];
	
	if(numD == 4)
		for(int i=0;i<n;i++){
			a[i]=rand()%9999;
		}
	
	if(numD == 6)
		for(int i=0;i<n;i++){
			a[i]=rand()%999999;
		}
	if(numD == 8)
		for(int i=0;i<n;i++){
			a[i]=rand()%99999999;
		}
	
	cout<<endl<<"Arreglo inicial "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
// Bases --------------------------
int max(int *a,int n){
	int max = a[0];
	for (int i=1;i<n;i++)
		if(a[i]>max)
			max=a[i];
	return max;
}
void ordenamiento1(int *a,int n, int exp){
	int salida[n];
	int i, cuenta[10] = {0};
	for(i=0;i<n;i++)
		cuenta[(a[i]/exp)%10 ]++;
		
	for(i=1;i<10;i++)
		cuenta[i]+=cuenta[i-1];
		
	for(i=n-1;i>=0;i--){
		salida[cuenta[(a[i]/exp)%10]-1]=a[i];
		cuenta[(a[i]/exp)%10]--;
	}
	for (i=0;i<n;i++)
		a[i]=salida[i];
}

void bases(int *a,int n){
	int m=max(a,n);
	for(int exp=1;m/exp>0;exp*=10)
		ordenamiento1(a,n,exp);
}

// Imprimir arreglo Ordenado --------------------
void mostrarArreglo(int *a, int n){
	cout<<endl<<endl<<"Arreglo Ordenado (Ascendente) "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
