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

    PCFreq = double(li.QuadPart)/100000.0;

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
void multMatrices(int **,int **,int **,int,int,int,int);
void mostrarMatrizS(int **,int,int);

int **M1, **M2, **MS, n1,m1,n2,m2;

//------ FUNCIÓN MAIN ------------------------------

int main(){
	
	char retry;
		
	do {
	pedirDatos();
	cout<<endl<<endl;
	if(m1==n2){
		multMatrices(M1,M2,MS,n1,m1,n2,m2);
		cout<<endl;
		mostrarMatrizS(MS,n1,m2);
	}
	cout<<endl<<endl;
	printf (" Tiempo : %20d  ms \n", GetCounter());
 
	
	}
	while('q'!=retry || 'Q'!=retry );
	
	
	system("PAUSE");
	return 0;
}

// -------- FUNCIONES CON MATRICES -----------------

void pedirDatos(){
	cout<<"Filas de la matriz 1: ";cin>>n1;
	cout<<"Columnas de la matriz 1  y Filas de la matriz 2: ";cin>>m1;
	
	
//	cout<<"Filas de la matriz 2: ";cin>>n2;
	n2=m1;
	
	
	cout<<"Columnas de la matriz 2: ";cin>>m2;
	
	M1 = new int *[n1];
	for(int i=0;i<n1;i++){
		M1[i]=new int [m1];
	}
	cout<<"Llenado Matriz 1"<<endl<<endl;
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++){
			M1[i][j]=rand() %10;
			cout<<"|"<<M1[i][j]<<"|";
		}
	cout<<endl;
	}
			
	cout<<endl;
	//---------------------------------

	
	M2 = new int *[n2];
	for(int i=0;i<n2;i++){
		M2[i]=new int [m2];
	}
	
	MS = new int *[n1];
	for(int i=0;i<n1;i++){
		MS[i]=new int [m2];
	}
	
	cout<<"Llenado Matriz 2"<<endl<<endl;
	for(int i=0;i<n2;i++){
		for(int j=0;j<m2;j++){
			M2[i][j]=rand() %10;
			cout<<"|"<<M2[i][j]<<"|";
		}
	cout<<endl;
	}
}

void multMatrices(int **M1,int **M2,int ** MS,int n1,int m1,int n2, int m2){
	cout<<"Multiplicando matrices..."<<endl<<endl;
	if(m1!=n2){
		cout<<"NO SE PUEDEN MULTIPLICAR LAS MATRICES, PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A ES DIFERENTE AL NUMERO DE FILAS DE LA MATRIZ B"<<endl;
	}else{
		StartCounter();
		for(int i=0;i<n1;i++){
			for(int j=0;j<m2;j++){
				MS[i][j] = 0;
				for(int k=0;k<n2;k++)
					MS[i][j] = MS[i][j] + M1[i][k] * M2[k][j];
		}
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
