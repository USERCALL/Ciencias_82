/*
Cristian Eduardo Ríos Guarín - 20141020058
Diego Alejandro Henrnadez - 20141020271
*/
#include<iostream>
#include<stdlib.h>
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
void residuo(int *,int,int,int);
void mostrarArreglo(int *,int);

int *a,n,numB;

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
		residuo(a,0,n,numB);
		//asigna el valor de tiempo
		double tiempo = GetCounter(); 
		
		entrada<< n <<" -> (numBits) "<<numB<<" -> (tiempo) "<<tiempo<<endl; 
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
	cout<<"Ingrese la cantidad de bits (4/8/16): ";cin>>numB;
	//srand(time(NULL));
	a = new int [n];
	int num = pow(2,numB);
	//cout<<num;		
	
	//Llenar desordenadamente	
	for(int i=0;i<n;i++){
		a[i]=rand()%num;
	}
	
	cout<<endl<<"Arreglo inicial "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
// Intercambio de Residuos --------------------------

unsigned bits (int x, int k, int j){
 return (x>>k)&~(~0<<j);
}

void residuo(int *a,int izq,int der, int b){
	int i, j,aux;
	if (der>izq && b>0){
		i= izq; j=der;
		while(j!=i){
			while(!bits(a[i],b,1) && i<j)i++;
			while(bits(a[j],b,1) && j>i)j--;
			//cout<<endl<<endl<<"intercambio"<<endl;
			//cout<<"aux:"<<aux<<", a[i]:"<<a[i]<<", a[j]:"<<a[j]<<endl;
			aux = a[i];
			//cout<<"aux: "<<aux<<", a[i]:"<<a[i]<<endl;
			a[i] = a[j];
			//cout<<"a[i]: "<<a[i]<<", a[j]:"<<a[j]<<endl;
			a[j] = aux;
			//cout<<"a[j]:"<<a[j]<<", aux:"<<aux<<endl;
			//cout<<"---------------------------"<<endl;
        }
        if (!bits(a[i],b,1)) j++;
        residuo(a, izq, j-1, b-1);
        residuo(a, j, der, b-1);
    }
}

// Imprimir arreglo Ordenado --------------------
void mostrarArreglo(int *a, int n){
	cout<<endl<<endl<<"Arreglo Ordenado (Ascendente) "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
