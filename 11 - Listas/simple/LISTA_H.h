#ifndef LISTA_H
#define LISTA_H
#include <cstdlib>
#include <iostream>

using namespace std;
template <class T>

struct Nodo
{
    Nodo <T> *sig;
    T info;
};

template <class T>
class Lista
{
    Nodo <T> *cab;
    int tam;

    public: Lista()
    {
        cab = NULL;
        tam = 0;
    }

    void imprimir();
    bool lista_vacia();
    int tamanio_lista();
    T obtener_dato(int pos);
    bool eliminar(int pos);
    void  insertar_inicio(T infoNueva);
    void  insertar_final(T infoNueva);
    void insertar_pos(T infoNueva, int pos);

};

template <class T>
void Lista<T>:: insertar_pos(T infoNueva, int pos)
{
    if(pos > tam)
        insertar_final(infoNueva);
    else
    {
        if(pos == 1)
            insertar_inicio(infoNueva);
        else
        {
            Nodo <T>  *nuevo;
            Nodo <T>  *aux;

            nuevo = new Nodo <T>;
            nuevo->info = infoNueva;
            aux = cab;
            int p = 1;
            while (p < pos-1)
            {
                aux = aux->sig;
              }
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
            tam++;
        }

    }
}

template <class T>
void Lista<T>::insertar_final(T infoNueva)
{
    Nodo <T> *nuevo;
    nuevo = new Nodo <T>;
    nuevo->info = infoNueva;
    nuevo->sig = NULL;
   
    if(tam == 0)
    {
    	cout<<"inserta"<<endl;
        cab = nuevo;
        	
    }
    else
    {
        Nodo <T> *aux;
        aux = cab;
        while(aux->sig != NULL )
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
    tam++;
}

template <class T>
void Lista<T>::insertar_inicio(T infoNueva)
{
    Nodo <T> *nuevo;
    nuevo = new Nodo <T>;
    nuevo->info = infoNueva;
    nuevo->sig = cab;
    cab = nuevo;
    tam++;
}

template <class T>
T Lista<T>::obtener_dato(int pos)
{
    Nodo <T> *aux;
    aux = cab;
    int p = 1;
    while(p < pos && aux->sig != NULL )
    {
        aux = aux->sig;
        p++;
    }
    if(aux != NULL)
        return aux->info;
    return 0;
}


template <class T>
bool Lista<T>::eliminar(int pos)
{
    if(tam >= pos)
    {
        Nodo <T> *temp;
        temp = cab;

        if(pos == 1)
        {
            cab = temp->sig;
            delete temp;
        }
        else
        {
            for(int i = 1; i<pos-1; i++)
            {
                temp = temp->sig;
            }
        Nodo <T> *aux;
        aux = temp->sig;
        temp->sig = aux->sig;
        delete aux;
        }
        tam--;
        return true;
    }
    else
        return false;
}


template <class T>
int Lista<T>::tamanio_lista()
{
    return tam;
}


template <class T>
bool Lista<T>::lista_vacia()
{
    if(0 == tam)
        return true;
    else
        return false;
}

template <class T>
void Lista<T>::imprimir()
{
    if(lista_vacia())
        cout << "La lista no tiene informacion" << endl;
    else
    {
        cout << "La informacion de la lista es :" << endl;

        Nodo <T> *aux;

        aux = cab;
        int pos = 1;
        while(aux != NULL )
        {
            cout << "La informacion en posicion [ " << pos << "] es : " << aux-> info << endl;
            aux = aux->sig;
            pos++;
        }

    }
}
#endif
