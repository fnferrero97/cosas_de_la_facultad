#ifndef COLA_H
#define COLA_H
#include "nodocola.h"

template <class T>
class Cola{
private:
    NodoCola<T>* frente;
    NodoCola<T>* fondo;
public:
    Cola(){
        this->frente = nullptr;
        this->fondo = nullptr;
    }

    void alta(T ndato){
        NodoCola<T>* nuevo_nodo = new NodoCola<T>(ndato);

        if (frente == nullptr){
            frente = nuevo_nodo;
        } else {
            fondo->setLink(nuevo_nodo);
        }

        fondo = nuevo_nodo;
    }

    T obtener(){
        T dato = frente->getDato();
        NodoCola<T>* aux = frente;

        if (frente == fondo){
            frente = nullptr;
            fondo = nullptr;
        } else {
            frente = frente->getLink();
        }

        delete aux;
        return dato;
    }

    bool vacia(){
        return frente == nullptr && fondo == nullptr;
    }
};

#endif // COLA_H
