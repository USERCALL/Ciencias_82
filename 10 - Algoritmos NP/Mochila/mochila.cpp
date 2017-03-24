#include <iostream>
#include <windows.h>

/*Libreria maneja archivos*/
#include<fstream>

using namespace std; 


// auto indent http://format.krzaq.cc/

//------------------------- CALCULAR TIEMPO ----------------------------------

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter(){
	
	PCFreq = 0.0;// limpiadno basura
	__int64 CounterStart = 0; //limpiando basura
	
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

	// Miscrosegundo -> 100000.0
    PCFreq = double(li.QuadPart*1000)/100;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter(){
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
//------------------------------------------------------------------------------


void Mochila(int n, int Peso[], int Valor[], int PMax){ 
     int *a = new int[PMax]; 
     int *temp = new int[PMax]; 
     int aux; 

     for (int i = 0; i <= PMax; i++){ 
          a[i] = 0; 
          temp[i] = -1; 
     } 

     a[0] = 0; 
     for (int i = 1; i <= PMax; i++) 
          for (int j = 0; j < n; j++) 
               if ((Peso[j] <= i) && (a[i] < a[i - Peso[j]] + Valor[j])){ 
                    a[i] = a[i - Peso[j]] + Valor[j]; 
                    temp[i] = j; 
               } 

     aux = PMax; 
     while ((aux > 0) && (temp[aux] != -1)){ 
          cout << "Se agrego " << temp[aux] + 1 << " ($"<<Valor[temp[aux]] << ", " << Peso[temp[aux]] << "Kg) Espacio disponible: " << aux - Peso[temp[aux]] << endl; 
          aux -= Peso[temp[aux]]; 
     } 
     cout << "Valor total: $" << a[PMax] << endl; 
     delete[] temp; 
     delete[] a; 
} 

int n; // catidad de objetos

void algoritmoMochila(int n) { 
    
	int  pMax = n/3; // peso maximo de objeto
    int vMax = 10; // prioridad de objeto 
     
    cout<<"Cantidad de objetos: "<< n <<endl; 
   
    int *peso = new int[n]; 
    int *valor = new int[n]; 
     
    for(int i=0; i<n; i++){ 
        
        peso[i]=rand()%pMax+1;
        valor[i]=rand()%vMax+1;
        
        cout << "Peso del objeto " << i + 1 << ": "<< peso[i]<<"\t"; 
		cout << "Valor (Beneficio) del objeto " << i + 1 << ": "<< valor[i]; 
          
        
     } 

    Mochila(n, peso, valor, pMax); 
  
} 

int main(){	
	cout<<"ALGORITMO DE MOCHILA"<<endl;


	/*Variable de de entrada*/
	ofstream entrada ; 
	
	/*abriendo archcivo*/
	//ios::out -> si exite el archivo sobre escribir
	//ios::app -> no permeite borarr el archivo, lamcenara lo nuevo

	entrada.open("resulados.txt", ios::out | ios::app);  


	if(entrada.fail()){
		//fail() error
		printf("Error de lectura");
		system("PAUSE");

	}else{
			
	
	for(n =50 ;n<=300;n+=10 ){
	
		StartCounter();
	
		algoritmoMochila(n);
		//asigna el valor de tiempo
		
		double tiempo = GetCounter(); 
		
		entrada<< n <<" - "<<tiempo<<endl; 
		cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms "<<endl;
		}	
	}
	system("PAUSE");
	return 0;
}
//------------------------------------------------------------------------------
