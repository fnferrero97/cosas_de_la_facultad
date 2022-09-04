#ifndef ArbolAVL_H
#define ArbolAVL_H
#include "ArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include <iostream>

template <class U>
class ArbolAVL : public ArbolBinarioBusqueda<U> {
private:
    int calcularBalance(NodoArbolBinarioBusqueda<U>* nodo){
        if (nodo == nullptr) return -1;
        return this->calcularAlturaRecursiva(nodo->getIzquierda()) - this->calcularAlturaRecursiva(nodo->getDerecha());
    }

    NodoArbolBinarioBusqueda<U>* insertar(NodoArbolBinarioBusqueda<U>* raiz, NodoArbolBinarioBusqueda<U>* nuevo_nodo){
        if (raiz == nullptr){
            return nuevo_nodo;
        }

        if (nuevo_nodo->getDato() < raiz->getDato()){
            raiz->setIzquierda(insertar(raiz->getIzquierda(), nuevo_nodo));
        } else if (nuevo_nodo->getDato() > raiz->getDato()){
            raiz->setDerecha(insertar(raiz->getDerecha(), nuevo_nodo));
        } else {
            std::cout << "YA EXISTE ESE VALOR\n";
            return raiz;
        }

        int dA = this->calcularBalance(raiz);

        if (dA > 1 && nuevo_nodo->getDato() < raiz->getIzquierda()->getDato()){
            return rotacionDerecha(raiz);
        }

        if (dA < -1 && nuevo_nodo->getDato() > raiz->getDerecha()->getDato()){
            return rotacionIzquierda(raiz);
        }

        if (dA > 1 && nuevo_nodo->getDato() > raiz->getIzquierda()->getDato()) {
            raiz->setIzquierda(rotacionIzquierda(raiz->getIzquierda()));
            return rotacionDerecha(raiz);
        }

        if (dA < -1 && nuevo_nodo->getDato() < raiz->getDerecha()->getDato()) {
            raiz->setDerecha(rotacionDerecha(raiz->getDerecha()));
            return rotacionIzquierda(raiz);
        }

        return raiz;
    }

    NodoArbolBinarioBusqueda<U>* rotacionDerecha(NodoArbolBinarioBusqueda<U>* y) {
        NodoArbolBinarioBusqueda<U>* x = y->getIzquierda();
        NodoArbolBinarioBusqueda<U>* T2 = x->getDerecha();

        x->setDerecha(y);
        y->setIzquierda(T2);

        return x;
    }

    NodoArbolBinarioBusqueda<U>* rotacionIzquierda(NodoArbolBinarioBusqueda<U>* x) {
      NodoArbolBinarioBusqueda<U>* y = x->getDerecha();
      NodoArbolBinarioBusqueda<U>* T2 = y->getIzquierda();

      y->setIzquierda(x);
      x->setDerecha(T2);

      return y;
    }


public:
    ArbolAVL(){
        this->raiz = nullptr;
    }

    void agregar(U ndato){
        NodoArbolBinarioBusqueda<U>* nuevo_nodo = new NodoArbolBinarioBusqueda<U>(ndato);
        this->raiz = this->insertar(this->getRaiz(), nuevo_nodo);
    }

    friend std::ostream& operator<<(std::ostream& os, ArbolBinarioBusqueda<U>*& arbol){
        if(arbol.getRaiz() != nullptr){
            return arbol.mostrarIterativoPorNiveles(os, arbol.getRaiz());
        } else {
            os << "El arbol esta vacio.\n";
            return os;
        }
    }

//    void eliminarValor(T dato){
//        this->raiz = this->eliminarRecursivo(dato, this->raiz);
//    }

};

#endif // ArbolAVL_H
