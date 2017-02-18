//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058
//Ciencias Computacion I (2017-02-07)

#include <iostream>

//Utilizo el espacio de nombre std para 
//evitar escribir  std::cin o cout

using namespace std;

int main(){
	
	//para la creaccion de array dinamicos, debo 
	// declarar el apuntador luego inicializarlo
	int **A, i, j, N, tam;
	 
	cout << "Ingrese N :"; cin >> N;
	
	A =  new int *[N];
	tam = tam + sizeof(&A);		 
	for(i=0; i<N; i++){
		A[i] = new int [N];
		for(j=0;j<N; j++){
			A[i][j]=j*i;
		}
	}
	
	for(i=0; i<N; i++){
		for(j=0;j<N; j++){
			cout << A[i][j] <<endl;		
			
			//Division de Bucle
			cout << "" <<endl;
		}
		delete A[i];	
	}
	tam=tam + ((N*N)*sizeof(N));
	delete []A;
	tam=tam + sizeof(N) + sizeof(i) + sizeof(j);
	cout<<"Tamanio N: "<<tam<<endl;
	//Evitar cierre 
	system("PAUSE");
	return 0;
}

