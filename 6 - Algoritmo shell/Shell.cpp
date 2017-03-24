/*
Algoritmo de busqueda
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

	// Miscrosegundo -> 100000.0
    PCFreq = double(li.QuadPart)/100000.0;

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
void shell(int *,int);
void mostrarArreglo(int *,int);

int *a,n;

int main(){	
	cout<<"ALGORITMO SHELL"<<endl; 


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
		
		
		shell(a,n);
		
		//asigna el valor de tiempo
		double tiempo = GetCounter(); 
		
		entrada<< n <<" -> "<<tiempo<<endl; 
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
	a = new int [n];
	
	//Llena de forma aleatoria
	for(int i=0;i<n;i++){
//		a[i] = rand () % 100000 + 10000;
		a[i] = i;
	}
	

	cout<<endl<<"Arreglo inicial "<<endl;
		
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}


// Método Shell --------------------------
//int a* -> arreglo y n longitud 
void shell(int *a,int n){
	int i, j, inc, temp;
	for(inc = 1 ; inc<n;inc=inc*3+1);
		while (inc > 0){
			for (i=inc; i < n; i++){
				j = i;
                temp = a[i];
                while ((j >= inc) && (a[j-inc] > temp)){
                	a[j] = a[j - inc];
                    j = j - inc;
                }
       			a[j] = temp;
			}
		inc/= 2;
	}
}

// Imprimir arreglo Ordenado --------------------
void mostrarArreglo(int *a, int n){
	
		
 
	cout<<"Arreglo Ordenado (Ascendente) "<<endl;
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	
}
