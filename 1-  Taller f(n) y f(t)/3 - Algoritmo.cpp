//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058
//Ciencias Computacion I  (2017-02-07)

#include <iostream>
using namespace std;

struct nodo{
	int x,y;
	nodo *sig;
};

int main(int argc, char** argv) {
	nodo *CAB = NULL, *AUX;
	int N, i, bytes;
	bytes=sizeof(&CAB);
	cout<<"Ingerse N: ";
	cin>>N;
	for(i=0;i<N;i++){
		AUX = new nodo;
		AUX -> x=i;
		AUX -> y=N-i;
		AUX->sig=CAB;
		CAB=AUX;
	}
	
	AUX=CAB;
	while(AUX!=NULL){
		bytes = bytes + sizeof(AUX->x) + sizeof(AUX->y) + sizeof(&AUX);
		cout<<AUX->x<<AUX->y<<endl;
		AUX=AUX->sig;
	}
	
	for(AUX=CAB->sig;AUX!=NULL;AUX=AUX->sig){
		delete CAB;
		CAB=AUX;
	}
	bytes = bytes + sizeof(N) + sizeof(i);
	cout<<"el Numero de bytes es: "<<bytes<<endl;
	return 0;
}
