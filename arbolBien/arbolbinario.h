#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>
#include <ostream>
#include "nodoarbolbinario.h"
#include "pila.h"

template <class T>
class ArbolBinario{
private:
    NodoArbolBinario<T>* raiz;

    std::ostream& mostrarRecursivoPreOrder(std::ostream& os, NodoArbolBinario<T>* nodo){
         if(nodo != nullptr){
             os << nodo->getDato() << " - ";
             mostrar(os, nodo->getIzquierda());
             mostrar(os, nodo->getDerecha());
         }
         return os;
    }

    std::ostream& mostrarRecursivoInOrder(std::ostream& os, NodoArbolBinario<T>* nodo){
         if(nodo != nullptr){
             mostrar(os, nodo->getIzquierda());
             os << nodo->getDato() << " - ";
             mostrar(os, nodo->getDerecha());
         }
         return os;
    }

    std::ostream& mostrarRecursivoPostOrder(std::ostream& os, NodoArbolBinario<T>* nodo){
         if(nodo != nullptr){
             mostrar(os, nodo->getIzquierda());
             mostrar(os, nodo->getDerecha());
             os << nodo->getDato() << " - ";
         }
         return os;
    }

    std::ostream& mostrarIterativoPreOrder(std::ostream& os, NodoArbolBinario<T>* nodo){
        NodoArbolBinario<T>* aux = nodo;
        Pila<NodoArbolBinario<T>*> pila;

         if(aux != nullptr){
             pila.alta_pila(aux);
             while(!pila.pila_vacia()){
                 aux = pila.obtener_pila();
                 os << aux->getDato() << " -- ";

                 if (aux->getDerecha() != nullptr){
                     pila.alta_pila(aux->getDerecha());
                 }

                 if (aux->getIzquierda() != nullptr){
                     pila.alta_pila(aux->getIzquierda());
                 }
             }
         }
         return os;
    }

    std::ostream& mostrarIterativoInOrder(std::ostream& os, NodoArbolBinario<T>* nodo){
        NodoArbolBinario<T>* aux = nodo;
        Pila<NodoArbolBinario<T>*> pila;
        bool termino = false;

        while(!termino){
         if(aux != nullptr){
             pila.alta_pila(aux);
             aux = aux->getIzquierda();
         } else {
             if (!pila.pila_vacia()){
                 aux = pila.obtener_pila();
                 os << aux->getDato() << " -- ";
                 aux = aux->getDerecha();
             } else {
                 termino = true;
             }
           }
         }
         return os;
    }

    std::ostream& mostrarIterativoPostOrder(std::ostream& os, NodoArbolBinario<T>* nodo){
        NodoArbolBinario<T>* aux1 = nodo;
        NodoArbolBinario<T>* aux2;
        Pila<NodoArbolBinario<T>*> pila;
        Pila<NodoArbolBinario<T>*> pilaDos;

        pila.alta_pila(aux1);

        while(!pila.pila_vacia()){
            aux2 = pila.obtener_pila();
            pilaDos.alta_pila(aux2);

            if(aux2->getIzquierda()) pila.alta_pila(aux2->getIzquierda());
            if(aux2->getDerecha()) pila.alta_pila(aux2->getDerecha());
        }

        while (!pilaDos.pila_vacia()){
            aux2 = pilaDos.obtener_pila();
            os << aux2->getDato() << " -- ";
        }

         return os;
    }

    NodoArbolBinario<T>* insertarRecursivo(T ndato, NodoArbolBinario<T>* nodo){
        if (!nodo){
          //nodo == nullptr
            return new NodoArbolBinario(ndato);
        } else if (ndato < nodo->getDato()){
            nodo->setIzquierda(insertarRecursivo(ndato, nodo->getIzquierda()));
        } else if (ndato > nodo->getDato()){
            nodo->setDerecha(insertarRecursivo(ndato, nodo->getDerecha()));
        } else if (nodo->getDato() == ndato){
            std::cout << "El dato " << ndato << " ya existe.\n";
        }
        return nodo;
    }

    NodoArbolBinario<T>* insertarIterativo(T ndato, NodoArbolBinario<T>* nodo){
        NodoArbolBinario<T>* nuevo_nodo = new NodoArbolBinario<T>(ndato);
        NodoArbolBinario<T>* aux = nodo;

        if (aux == nullptr) {
            return nuevo_nodo;
        } else {
            bool bandera = true;

            while(bandera){
                if (nuevo_nodo->getDato() < aux->getDato()){
                    if (aux->getIzquierda() == nullptr){
                        aux->setIzquierda(nuevo_nodo);
                        bandera = false;
                    } else {
                        aux = aux->getIzquierda();
                    }
                } else if (nuevo_nodo->getDato() > aux->getDato()){
                    if (aux->getDerecha() == nullptr){
                        aux->setDerecha(nuevo_nodo);
                        bandera = false;
                    } else {
                        aux = aux->getDerecha();
                    }
                } else if (nuevo_nodo->getDato() == aux->getDato()){
                    std::cout << "El dato " << ndato << " ya existe.\n";
                    return nodo;
                }
            }
            return nodo;
        }
    }

    void destruirNodo(NodoArbolBinario<T>* nodo){
        if(nodo != nullptr){
            destruirNodo(nodo->getIzquierda());
            destruirNodo(nodo->getDerecha());
            delete nodo;
        }
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
    this->raiz = this->insertarRecursivo(ndato, this->getRaiz());
}

friend std::ostream& operator<<(std::ostream& os, ArbolBinario<T>& arbol){
    if(arbol.getRaiz() != nullptr){
        return arbol.mostrarIterativoInOrder(os, arbol.getRaiz());
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

