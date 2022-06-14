#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>
#include <ostream>
#include "nodoarbolbinario.h"

template <class T>
class ArbolBinario{
private:
    NodoArbolBinario<T>* raiz;

    std::ostream& mostrar(std::ostream& os, NodoArbolBinario<T>* nodo){
         if(nodo != nullptr){
             mostrar(os, nodo->getIzquierda());
             os << nodo->getDato() << " - ";
             mostrar(os, nodo->getDerecha());
         }
         return os;
    }

    void destruirNodo(NodoArbolBinario<T>* nodo){
        if(nodo != nullptr){
            destruirNodo(nodo->getIzquierda());
            destruirNodo(nodo->getDerecha());
            delete nodo;
        }
    }

    NodoArbolBinario<T>* insertarEn(T ndato, NodoArbolBinario<T>* nodo){
        if (!nodo){
            return new NodoArbolBinario(ndato);
        } else if (nodo->getDato() > ndato){
            nodo->setIzquierda(insertarEn(ndato, nodo->getIzquierda()));
        } else if (nodo->getDato() < ndato){
            nodo->setDerecha(insertarEn(ndato, nodo->getDerecha()));
        } else if (nodo->getDato() == ndato){
            std::cout << "El dato " << ndato << " ya existe.\n";
        }
        return nodo;
    }
public:

ArbolBinario(){
    this->raiz = nullptr;
}

~ArbolBinario(){
    this->limpiar();
}

void limpiar(){
    this->destruirNodo(this->getRaiz());
    this->raiz = nullptr;
}

void agregar(T ndato){
    this->raiz = this->insertarEn(ndato, this->getRaiz());
}

friend std::ostream& operator<<(std::ostream& os, ArbolBinario<T>& arbol){
    if(arbol.getRaiz() != nullptr){
        return arbol.mostrar(os, arbol.getRaiz());
    } else {
        os << "El arbol esta vacio.\n";
        return os;
    }
}

NodoArbolBinario<T>* getRaiz() const{
    return this->raiz;
}

};

//inorde

#endif // ARBOLBINARIO_H

