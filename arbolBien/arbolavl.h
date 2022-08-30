#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#define ESPACIO 10

#include "nodoarbolbinario.h"
#include "cola.h"
#include "pila.h"
#include <iostream>

template <class T>
class arbolAVL{
private:
    NodoArbolBinario<T>* raiz;

    std::ostream& mostrarIterativoPreOrder(std::ostream& os, NodoArbolBinario<T>* nodo){
        NodoArbolBinario<T>* aux = nodo;
        Pila<NodoArbolBinario<T>*> pila;

         if(aux != nullptr){
             pila.alta_pila(aux);
             while(!pila.pila_vacia()){
                 aux = pila.obtener_pila();
                 os << aux->getDato() << " -- ";

                 if (aux->getDerecha() != nullptr) pila.alta_pila(aux->getDerecha());
                 if (aux->getIzquierda() != nullptr) pila.alta_pila(aux->getIzquierda());
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

    std::ostream& mostrarIterativoPorNiveles(std::ostream& os, NodoArbolBinario<T>* nodo){
        NodoArbolBinario<T>* aux;
        Cola<NodoArbolBinario<T>*> cola;

        cola.alta(nodo);

        while(!cola.vacia()){
            aux = cola.obtener();
            os << aux->getDato() << " -- ";

            if(aux->getIzquierda() != nullptr) cola.alta(aux->getIzquierda());
            if(aux->getDerecha() != nullptr) cola.alta(aux->getDerecha());
        }
        return os;
    }

    int calcularAlturaRecursiva(NodoArbolBinario<T>* nodo){

        if (nodo == nullptr) {
            return -1;
        } else {
            int izq = calcularAlturaRecursiva(nodo->getIzquierda());
            int der = calcularAlturaRecursiva(nodo->getDerecha());
            return izq > der ? izq + 1 : der + 1;
        }
    }

    int calcularBALANCE(NodoArbolBinario<T>* nodo){
        if (nodo == nullptr) return -1;
        return calcularAlturaRecursiva(nodo->getIzquierda()) - calcularAlturaRecursiva(nodo->getDerecha());
    }

    NodoArbolBinario<T>* insertarRecursivo(NodoArbolBinario<T>* raiz, NodoArbolBinario<T>* nuevo_nodo){

        if (raiz == nullptr){
            return nuevo_nodo;
        }

        if (nuevo_nodo->getDato() < raiz->getDato()){
            raiz->setIzquierda(insertarRecursivo(raiz->getIzquierda(), nuevo_nodo));
        } else if (nuevo_nodo->getDato() > raiz->getDato()){
            raiz->setDerecha(insertarRecursivo(raiz->getDerecha(), nuevo_nodo));
        } else {
            std::cout << "YA EXISTE ESE VALOR\n";
            return raiz;
        }

        int dA = this->calcularBALANCE(raiz);

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

    NodoArbolBinario<T>* rotacionDerecha(NodoArbolBinario<T>* y) {
        NodoArbolBinario<T>* x = y->getIzquierda();
        NodoArbolBinario<T>* T2 = x->getDerecha();

        // Perform rotation
        x->setDerecha(y);
        y->setIzquierda(T2);

        return x;
    }

    NodoArbolBinario<T>* rotacionIzquierda(NodoArbolBinario<T>* x) {
      NodoArbolBinario<T>* y = x->getDerecha();
      NodoArbolBinario<T>* T2 = y->getIzquierda();

      // Perform rotation
      y->setIzquierda(x);
      x->setDerecha(T2);

      return y;
    }

    NodoArbolBinario<T>* valorMinimo(NodoArbolBinario<T>* nodo){
        NodoArbolBinario<T>* aux = nodo;

        while (aux->getIzquierda() != nullptr){
            aux = aux->getIzquierda();
        }
        return aux;
    }

    NodoArbolBinario<T>* valorMaximo(NodoArbolBinario<T>* nodo){
        NodoArbolBinario<T>* aux = nodo;

        while (aux->getDerecha() != nullptr){
            aux = aux->getDerecha();
        }
        return aux;
    }

public:
    arbolAVL(){
        this->raiz = nullptr;
    }

    void agregar(T ndato){
        NodoArbolBinario<T>* nuevo_nodo = new NodoArbolBinario<T>(ndato);
        this->raiz = this->insertarRecursivo(this->getRaiz(), nuevo_nodo);
    }

    friend std::ostream& operator<<(std::ostream& os, arbolAVL<T>& arbol){
        if(arbol.getRaiz() != nullptr){
            return arbol.mostrarIterativoPorNiveles(os, arbol.getRaiz());
        } else {
            os << "El arbol esta vacio.\n";
            return os;
        }
    }

    NodoArbolBinario<T>* getRaiz() const{
        return this->raiz;
    }

    int calcularAltura(){
       return this->calcularAlturaRecursiva(this->raiz) + 1;
    }

    const T& getMinimo(){
        NodoArbolBinario<T>* minimo = this->valorMinimo(this->raiz);
        return minimo->getDato();
    }

    const T& getMaximo(){
        NodoArbolBinario<T>* maximo = this->valorMaximo(this->raiz);
        return maximo->getDato();
    }

    void mostarHorizontal2D(NodoArbolBinario<T>* raiz, int cantEspacios) {
        if (raiz == nullptr) return;

        cantEspacios += ESPACIO;
        mostarHorizontal2D(raiz->getDerecha(), cantEspacios);

        std::cout << "\n";

        for (int i = ESPACIO; i < cantEspacios; i++){
          std::cout << " "; // 5.1
        }

        std::cout << raiz->getDato()<< "\n";

        mostarHorizontal2D(raiz->getIzquierda(), cantEspacios);
      }

//    void eliminarValor(T dato){
//        this->raiz = this->eliminarRecursivo(dato, this->raiz);
//    }
};

#endif // ARBOLAVL_H
