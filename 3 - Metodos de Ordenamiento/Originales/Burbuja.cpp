/*
Algoritmo de burbuja
Cristian Eduardo Ríos Guarín - 20141020058
*/

/*

StartCounter();
cout<<"Tiempo: "<< GetCounter()<<"ms."<<endl;

*/

#include<iostream>
#include<stdlib.h>
#include<windows.h>


/*Libreria maneja archivos*/
#include<fstream>

using namespace std;

//------- CALCULAR TIEMPO ------------------------
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

void pedirDatos();
void burbuja(int *,int);
void mostrarArreglo(int *,int);

int *a,n;

int main(){	
	cout<<"ALGORITMO DE ORDENAMIENTO POR METODO BURBUJA"<<endl<<endl<<endl;
	pedirDatos();
	StartCounter();
	burbuja(a,n);
	cout<<endl<<endl<<"Tiempo: "<< GetCounter()<<"ms."<<endl;
	mostrarArreglo(a,n);
	cout<<endl;
		
	system("Pause");
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
		a[i]=num;
		num++;
	}
	
	
	/*
	//Llenar desordenadamente
	int num = n;
	for(int i=0;i<n;i++){
		a[i]=num;
		num--;
	}
	*/
	
	cout<<endl<<"Arreglo inicial "<<endl<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}

// Método burbuja --------------------------
void burbuja(int *a,int n){
	int pos, aux;
	//empieza de forma decremental
	for(int i=n;i>0;i--){
		for(int j=1;j<i;j++){
			if(a[j-1]>a[j]){
				aux = a[j-1];
				a[j-1] = a[j];
				a[j] = aux;
			}
		}
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
