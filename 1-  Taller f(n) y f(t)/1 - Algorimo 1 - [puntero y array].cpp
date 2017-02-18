//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058
//Ciencias Computacion I  (2017-02-07)

#include <iostream>

//Utilizo el espacio de nombre std para 
//evitar escribir  std::cin o cout

using namespace std;

int main(){
	
	//para la creaccion de array dinamicos, debo 
	// declarar el apuntador luego inicializarlo

	//apuntador para crear arreglo de N elementos
	int *A;
	// variable N
	int N, i, j, tam;
	cout << "Ingrese tamanio arreglo : "; cin >> N;
		
	//variable i
	for(i=0; i<N; i++){ 
	
	//PROBLEMA	
	//inicializo matriz de n elementos
	 A =  new int [N]; 
		
			//variable j
		for( j=0;j<N; j++){ 
		
			// 0,0 -> A[0] = 0 
			// 0,1 -> A[1] = 0 .....
			// hasta que rompe ciclo y borra A
			
			// 1,0 -> A[0] = 0
				// 1,1 -> A[1] = 1
							
			//n-1 * n-1 incrementado

			A[j]=j*i;
			cout << A[j] <<endl;
		}
	
		//Division de Bucle
		cout << "--------- \n" <<endl;
		tam= sizeof(&A) + sizeof(N);
		delete []A;
	}
	tam = tam + sizeof(N)+sizeof(i)+sizeof(j);
	cout<<"Tamanio N: "<<tam<<endl;
	
	//Evitar cierre 
	system("PAUSE");
	return 0;
}
