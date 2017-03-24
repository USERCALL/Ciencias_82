#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
/*Libreria maneja archivos*/
#include <fstream>

using namespace std;

int DIMENSION;

//------------------------- CALCULAR TIEMPO ----------------------------------

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    CounterStart = 0;
    if (!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    // Miscrosegundo -> 100000.0
    PCFreq = double(li.QuadPart) / 100000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}

double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart - CounterStart) / PCFreq;
}
//------------------------------------------------------------------------------

bool colocarReina(int** t, int fila);
void imprimir(int** lab);
bool amenazada(int** t, int fila, int columna);


int main(int argc, char* argv[])
{
    int** t;

    /*Variable de de entrada*/
    ofstream entrada;
    /*abriendo archcivo*/
    // ios::out -> si exite el archivo sobre escribir
    // ios::app -> no permeite borarr el archivo, lamcenara lo nuevo
    entrada.open("resultados.txt", ios::out | ios::app);
    if (entrada.fail())
    {
        // fail() error
        printf("Error de lectura");
        system("pause");
    }
    else
    {
    	for(DIMENSION= 2; DIMENSION<30;DIMENSION+=1)
		{
		
	        cout << "Dimension del arreglo: "<< DIMENSION<<endl;
	        
	        t = new int*[DIMENSION];
	        for (int i = 0; i < DIMENSION; i++)
	            t[i] = new int[DIMENSION];
	
	        for (int i = 0; i < DIMENSION; i++)
	            for (int j = 0; j < DIMENSION; j++)
	                t[i][j] = 0;
	                
	        StartCounter();
	        colocarReina(t, 0);
	        double tiempo = GetCounter();
	
	        entrada << DIMENSION << " - " << tiempo << endl;
	        cout << endl << endl << "Tiempo: " << tiempo << "ms " << endl;
		delete t;
		}
	}	
		
    entrada.close();
    system("PAUSE");
   return EXIT_SUCCESS;
   
}

bool colocarReina(int** t, int fila)
{
    bool tmp;
    if (fila == DIMENSION)
    {
        cout << "solucion encontrada \n";
        imprimir(t);
        return true;
    }

    for (int columna = 0; columna < DIMENSION; columna++)
    {
        if (!amenazada(t, fila, columna))
        {
            t[fila][columna] = fila + 1; // reina i-esima
            tmp = colocarReina(t, fila + 1);
            if (tmp == true)
                return true;
            // borra soluciòn invalida
            t[fila][columna] = 0;
        }
    }
    return false;
}

void imprimir(int** lab)
{
    cout << "Arreglo:" << endl;
    for (int i = 0; i < DIMENSION; i++)
    {
        for (int j = 0; j < DIMENSION; j++)
            cout << lab[i][j] << "\t";
        cout << endl;
    }
}

bool amenazada(int** t, int fila, int columna)
{
    int i, f, c;
    // revisa fila y columna
    for (i = 0; i < DIMENSION; i++)
    {
        if (t[fila][i] != 0 || t[i][columna] != 0)
        {
            return true;
        }
    }
    // arriba a la izquierda
    for (f = fila, c = columna; f >= 0 && c >= 0; f--, c--)
    {
        if (t[f][c] != 0)
            return true;
    }
    // arriba a la derecha
    for (f = fila, c = columna; f >= 0 && c < DIMENSION; f--, c++)
    {
        if (t[f][c] != 0)
            return true;
    }
    // abajo a la izquierda
    for (f = fila, c = columna; f < DIMENSION && c >= 0; f++, c--)
    {
        if (t[f][c] != 0)
            return true;
    }
    // abajo derecha
    for (f = fila, c = columna; f < DIMENSION && c < DIMENSION; f++, c++)
    {
        if (t[f][c] != 0)
            return true;
    }
    return false;
}


