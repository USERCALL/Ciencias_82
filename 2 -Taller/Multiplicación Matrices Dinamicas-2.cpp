//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058

#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include <stdio.h>

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
long GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return long(li.QuadPart-CounterStart)/PCFreq;
}

//------- PROGRAMA SUMA MATRICES -------------------
void pedirDatos();
void multMatrices(int **,int **,int **,int,int);
void mostrarMatrizS(int **,int,int);

int **M1, **M2, **MS, n,m;

//------ FUNCIÓN MAIN ------------------------------

int main(){
	
	char retry;
		
	do {
		
	pedirDatos();
	cout<<endl<<endl;
	multMatrices(M1,M2,MS,n,m);
	cout<<endl;
	mostrarMatrizS(MS,n,m);
	
	cout<<endl<<endl;
	//cout<<"Tiempo: "<< GetCounter()<<"ms."<<endl;
	
	
	printf (" Tiempo : %20d  ms \n", GetCounter());
 
	 cout<<"si quieres salir Q -> ";
	 cin >> retry;
    }
	while('q'!=retry || 'Q'!=retry );
	
	
	
	system("PAUSE");
	return 0;
}

// -------- FUNCIONES CON MATRICES -----------------

void pedirDatos(){
	cout<<"Filas: ";cin>>n;
	cout<<"Columnas: ";cin>>m;
	
	M1 = new int *[n];
	MS = new int *[n];
	for(int i=0;i<n;i++){
		M1[i]=new int [m];
		MS[i] = new int [m];
	}
	cout<<"Llenado Matriz 1"<<endl<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			M1[i][j]=rand() %10;
			cout<<"|"<<M1[i][j]<<"|";
		}
	cout<<endl;
	}
			
	cout<<endl;
	//---------------------------------
	M2 = new int *[n];
	for(int i=0;i<n;i++){
		M2[i]=new int [m];
	}
	cout<<"Llenado Matriz 2"<<endl<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			M2[i][j]=rand() %10;
			cout<<"|"<<M2[i][j]<<"|";
		}
	cout<<endl;
	}
}

void multMatrices(int **M1,int **M2,int ** MS,int n,int m){
	cout<<"Multiplicando matrices..."<<endl;
	StartCounter();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			MS[i][j] = 0;
			for(int k=0;k<m;k++)
				MS[i][j] = MS[i][j] + M1[i][k] * M2[k][j];
		}
	}
}

void mostrarMatrizS(int **MS,int n,int m){
	cout<<"Imprimiendo Matriz Resultante"<<endl<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<"|"<<MS[i][j]<<"|";
	cout<<endl;
	}
}
