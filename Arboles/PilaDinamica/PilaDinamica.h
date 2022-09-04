#ifndef PILA_H
#define PILA_H
#include "NodoPilaDinamica.h"
#include <iostream>

template <class T>
class PilaDinamica{
private:
    NodoPilaDinamica<T>* ultimo;
public:
    PilaDinamica(){
        this->ultimo = nullptr;
    }

    void altaPila(T ndato){
        NodoPilaDinamica<T>* nuevo_nodo = new NodoPilaDinamica<T>(ndato);
        nuevo_nodo->setLink(this->ultimo);
        this->ultimo = nuevo_nodo;
    }

    T obtenerPila(){
        T dato = this->ultimo->getDato();
        NodoPilaDinamica<T>* aux = this->ultimo;
        this->ultimo = aux->getLink();
        delete aux;
        return dato;
    }

    bool vaciaPila(){
        return this->ultimo == nullptr;
    }

};

#endif // PILA_H
