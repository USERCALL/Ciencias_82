/*
#include <iostream>

 run this program using the console pauser or add your own getch, system("pause") or input loop 

int main(int argc, char** argv) {
	return 0;
}*/

#include <iostream>
#include <time.h>
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


ofstream entrada ; 
	
void Mochila(int n, int Peso[], int Valor[], int PMax){ 
     
     
	int *a = new int[PMax]; 
    int *temp = new int[PMax]; 
	int aux; 
	
    for(int i = 0; i <= PMax; i++){ 
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
          cout << "Se agrego " << temp[aux] + 1 << " ( $  "<<Valor[temp[aux]] << " , " << Peso[temp[aux]] << " Kg) Espacio disponible: " << aux - Peso[temp[aux]] << endl; 
          aux -= Peso[temp[aux]]; 
     } 
     cout << "Valor total: $" << a[PMax] << endl; 
     delete[] temp; 
     delete[] a; 
     delete[] Peso;
} 

int n; // catidad de objetos

void algoritmoMochila(int n) { 
    
	int  pMax = n/3; // peso maximo de objeto
    int vMax = 10; // prioridad de objeto 
    
    if(pMax == 0 ){
		pMax=1; 
	}

    int *peso = new int[n]; 
    int *valor = new int[n]; 
     
     //lenamos el dos arrgloes que serian encadenados esquivalentes a un objeto
     
    for(int i=0; i<n; i++){ 
        
		//srand(time(NULL));
        
        int auxPeso = rand()%pMax+1;
		peso[i] = auxPeso;
        
        int auxValor = rand()%vMax+1;
        valor[i]= auxValor;
        
        cout << "Peso del objeto " << i + 1 << " : "<< peso[i]<<"\n"; 
		cout << "Valor (Beneficio) del objeto " << i + 1 << ": "<< valor[i]<<"\n"; 
		
	}		
     
    Mochila(n, peso, valor, pMax);
    
	delete valor;
    delete peso;

} 

int main(){	
	cout<<"ALGORITMO DE MOCHILA"<<endl;


	for(n = 1 ;n<=5;n+=1){
		entrada.open("resulados.txt", ios::out | ios::app);  
		
		StartCounter();
		algoritmoMochila(n);
		double tiempo = GetCounter(); 	//asigna el valor de tiempo
		
		entrada<< n <<" - "<<tiempo<<endl; 
		cout<<endl<<endl<<"Tiempo: "<< tiempo <<"ms "<<endl;
			
		entrada.close();
		system("PAUSE");
	}	
	
	system("PAUSE");
	return 0;
}
//------------------------------------------------------------------------------
