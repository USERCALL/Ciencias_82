#include "LISTA_H.h"

int main (){

	Lista<int> A; 
	
	A.insertar_final(8);
	A.insertar_inicio(2);
	A.insertar_pos(6, 2);
	A.insertar_pos(5, 2);
	
	A.eliminar(4);

	A.insertar_final(A.obtener_dato(1));
	A.imprimir();
	

}
