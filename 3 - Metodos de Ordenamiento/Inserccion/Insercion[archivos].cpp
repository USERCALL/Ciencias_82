/*
Algoritmo de inserción
Cristian Eduardo Ríos Guarín - 20141020058
Diego Alejandro Henrnadez - 20141020271
*/

#include<iostream>
#include<stdlib.h>
#include<windows.h>

/*Libreria maneja archivos*/
#include<fstream>
#include<conio.h>




using namespace std;


//------------------------- CALCULAR TIEMPO ----------------------------------
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/10000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
//------------------------------------------------------------------------------
//-----------------------------------------------------------------------------



void pedirDatos();
void insercion(int *,int);
void mostrarArreglo(int *,int);

int *a,n;

int main(){	
	cout<<"ALGORITMO DE ORDENAMIENTO POR METODO DE INSERCION"<<endl<<endl<<endl;


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
		StartCounter();
		insercion(a,n);
		
		double tiempo = GetCounter(); 
		entrada<< n <<" -> "<<tiempo<<endl; 
		cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms."<<endl;
		
		mostrarArreglo(a,n);
		cout<<endl;
		}	
	getch();
	return 0;
}
//------------------------------------------------------------------------------

void pedirDatos(){
	cout<<"Ingrese la cantidad de datos del arreglo: ";cin>>n;
	a = new int [n];
	
	/*
	//Llenar de forma aleatoria
	for(int i=0;i<n;i++){
		a[i] = rand () % 10;
	}
	*/
	
	
	//Llenar Ordenadamente
	int num = 1;
	for(int i=0;i<n;i++){
		a[i]=num*1000;
		num++;
	}
	
	
	/*
	//Llenar desordenadamente
	int num = n;
	for(int i=0;i<n;i++){
		a[i]=num*1000;
		num--;
	}
	*/
	
	cout<<endl<<"Arreglo inicial "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}

// Método de inserción --------------------------
//int a* -> arreglo y n longitud 
void insercion(int *a,int n){
	int pos, aux;
	for(int i=0;i<n;i++){
		pos = i;
		//aux -> tomo el primer valor de izquierda a derecha
		aux = a[i];
		while((pos>0) && (aux<a[pos-1])){
			a[pos] = a[pos-1];
			pos--;
		}
		a[pos] = aux;
	}
}

// Imprimir arreglo Ordenado --------------------
void mostrarArreglo(int *a, int n){
	cout<<endl<<endl<<"Arreglo Ordenado (Ascendente) "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	/*
	cout<<endl<<"Arreglo Ordenado (Descendente) "<<endl<<endl;
	for(int i=n-1;i>=0;i--)
		cout<<a[i]<<" ";
	cout<<endl;
	*/
}
