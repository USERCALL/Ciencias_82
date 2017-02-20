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
	
	CounterStart=0;
	PCFreq=0.0; 
	
		
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
void insercion(int *,int);
void busquedaBinaria(int *, int , int);
void mostrarArreglo(int *,int);


void fillArray();



int *a,n;

int main(){	
	cout<<"ALGORITMO DE BUSQUEDA BINARIA \n "<<endl; 
	
	int salir= 0 ; 
	
	n=10; 
	
	
	
	do{
		
		fillArray();
	
	
	
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
		
		
				
	//	pedirDatos();
		
		//proceso autoamtico
//		n = salir ; 
		
		insercion(a,n);
	/*	
		int num = n +1 ; 
		cout<<"Introduce un numero ";cin>>num;
		//empieza conteo
	*/
	//int num = a[n-2];
		StartCounter();	
	
		busquedaBinaria(a,n,n+1);
	
		//asigna el valor de tiempo
		double tiempo = GetCounter(); 
		
		entrada<< n <<" -> "<<tiempo<<endl; 
		cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms "<<endl;
	
	//	mostrarArreglo(a,n);
		cout<<endl;
	}	
	
//	cout << "\n Para salir oprima  (1)  ->   ";cin >> salir;
	
	
//	salir = salir + 10; 
	
n= n+10;	


	}while( n!=310 );

	
	getch();
	return 0;
}
//------------------------------------------------------------------------------

void pedirDatos(){
	cout<<" \n Ingrese la cantidad de datos del arreglo: ";cin>>n;
	a = new int [n];
	
	//Llena de forma aleatoria
	for(int i=0;i<n;i++){
		a[i] = rand () % 1000000 + 10000;
//		a[i] = i;
	}
	

//	cout<<endl<<"Arreglo inicial "<<endl;
		
//	for(int i=0;i<n;i++){
//		cout<<a[i]<<" ";
//	}
}


// Método de inserción --------------------------
//int a* -> arreglo y n longitud 
void insercion(int *a,int n){
	int pos, aux;
	for(int i=1;i<n;i++){
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
	
		
 
	cout<<"Arreglo Ordenado (Ascendente) "<<endl;
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	cout<<endl;
	
}

// int arreglo ordenado , longitud , numero buscado
void busquedaBinaria (int *array , int length,int searchNumber){
	
	bool isFind=false;
	
	
	int first = 0;
	int middle = 0;
	int last = length - 1;
	
	//nuemro a buscar se intoducira por defecto en el arrglo


	//mientras 
	while(first <= last){
		//simpre estaremos hññando la mitad del array
		middle = (first + last) / 2;
	//	cout << "\n first " << first<<endl;
	//	cout << "\n mitad " << middle<<endl;
	//	cout << "\n last " << last<<endl;
		
		
	//	cout << searchNumber<< " == ? "<<array[middle] <<endl;
		if(searchNumber==array[middle]){
			// + 1 equivalante a entender mejor el areglo
			cout <<" \n \n Se ha encontardo el numero : "<< searchNumber << " \n en la posicion : "<< middle + 1 <<endl; 
			break;
		}else{
			if (searchNumber<=array[middle-1]){ // revisa a la izauierda
				last=middle-1; // se reduce a la mitad
			}else{
			//if (searchNumber>=array[middle+1]){
				first=middle+1;
			}
			
		} 
		
	}
	
	// si no encuentra entonces 
	if ( !(first <= last) && !isFind){
		cout << " \n \n No se ha encontrado el nuemero \n " <<endl;
	}


}
void fillArray(){
	a = new int [n];
			//Llena de forma aleatoria
	for(int i=0;i<n;i++){
		a[i] = rand () % 1000000 + 10000;
//		a[i] = i;
	}
}
