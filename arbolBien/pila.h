#ifndef PILA_H
#define PILA_H
#include "nodopila.h"
#include <iostream>

template <class T>
class Pila{
private:
    NodoPila<T>* ultimo;
public:
    Pila(){
        this->ultimo = nullptr;
    }

    void alta_pila(T ndato){
        NodoPila<T>* nuevo_nodo = new NodoPila<T>(ndato);
        nuevo_nodo->setLink(this->ultimo);
        this->ultimo = nuevo_nodo;
    }

    T obtener_pila(){
        T dato = this->ultimo->getDato();
        NodoPila<T>* aux = this->ultimo;
        this->ultimo = aux->getLink();
        delete aux;
        return dato;
    }

    bool pila_vacia(){
        return this->ultimo == nullptr;
    }

};

#endif // PILA_H
