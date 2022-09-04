#ifndef ArbolBinarioBusqueda_H
#define ArbolBinarioBusqueda_H
#define ESPACIO 10
#include "NodoArbolBinarioBusqueda.h"
#include <PilaDinamica/PilaDinamica.h>
#include <ColaDinamica/ColaDinamica.h>
#include <iostream>
#include <ostream>


template <class T>
class ArbolBinarioBusqueda {
private:
    NodoArbolBinarioBusqueda<T>* raiz;

    std::ostream& mostrarRecursivoPreOrder(std::ostream& os, NodoArbolBinarioBusqueda<T>* nodo){
         if(nodo != nullptr){
             os << nodo->getDato() << " - ";
             mostrar(os, nodo->getIzquierda());
             mostrar(os, nodo->getDerecha());
         }
         return os;
    }

    std::ostream& mostrarRecursivoInOrder(std::ostream& os, NodoArbolBinarioBusqueda<T>* nodo){
         if(nodo != nullptr){
             mostrar(os, nodo->getIzquierda());
             os << nodo->getDato() << " - ";
             mostrar(os, nodo->getDerecha());
         }
         return os; 
    }

    std::ostream& mostrarRecursivoPostOrder(std::ostream& os, NodoArbolBinarioBusqueda<T>* nodo){
         if(nodo != nullptr){
             mostrar(os, nodo->getIzquierda());
             mostrar(os, nodo->getDerecha());
             os << nodo->getDato() << " - ";
         }
         return os;
    }

    std::ostream& mostrarIterativoPreOrder(std::ostream& os, NodoArbolBinarioBusqueda<T>* nodo){
        NodoArbolBinarioBusqueda<T>* aux = nodo;
        PilaDinamica<NodoArbolBinarioBusqueda<T>*> pila;

         if(aux != nullptr){
             pila.altaPila(aux);
             while(!pila.vaciaPila()){
                 aux = pila.obtenerPila();
                 os << aux->getDato() << " -- ";

                 if (aux->getDerecha() != nullptr) pila.altaPila(aux->getDerecha());
                 if (aux->getIzquierda() != nullptr) pila.altaPila(aux->getIzquierda());
             }
         }
         return os;
    }

    std::ostream& mostrarIterativoInOrder(std::ostream& os, NodoArbolBinarioBusqueda<T>* nodo){
        NodoArbolBinarioBusqueda<T>* aux = nodo;
        PilaDinamica<NodoArbolBinarioBusqueda<T>*> pila;
        bool termino = false;

        while(!termino){
         if(aux != nullptr){
             pila.altaPila(aux);
             aux = aux->getIzquierda();
         } else {
             if (!pila.vaciaPila()){
                 aux = pila.obtenerPila();
                 os << aux->getDato() << " -- ";
                 aux = aux->getDerecha();
             } else {
                 termino = true;
             }
           }
         }
         return os;
    }

    std::ostream& mostrarIterativoPostOrder(std::ostream& os, NodoArbolBinarioBusqueda<T>* nodo){
        NodoArbolBinarioBusqueda<T>* aux1 = nodo;
        NodoArbolBinarioBusqueda<T>* aux2;
        PilaDinamica<NodoArbolBinarioBusqueda<T>*> pila;
        PilaDinamica<NodoArbolBinarioBusqueda<T>*> pilaDos;

        pila.altaPila(aux1);

        while(!pila.vaciaPila()){
            aux2 = pila.obtenerPila();
            pilaDos.altaPila(aux2);

            if(aux2->getIzquierda()) pila.altaPila(aux2->getIzquierda());
            if(aux2->getDerecha()) pila.altaPila(aux2->getDerecha());
        }

        while (!pilaDos.vaciaPila()){
            aux2 = pilaDos.obtenerPila();
            os << aux2->getDato() << " -- ";
        }

         return os;
    }

    std::ostream& mostrarIterativoPorNiveles(std::ostream& os, NodoArbolBinarioBusqueda<T>* nodo){
        NodoArbolBinarioBusqueda<T>* aux;
        ColaDinamica<NodoArbolBinarioBusqueda<T>*> cola;

        cola.altaCola(nodo);

        while(!cola.vaciaCola()){
            aux = cola.obtenerCola();
            os << aux->getDato() << " -- ";

            if(aux->getIzquierda() != nullptr) cola.altaCola(aux->getIzquierda());
            if(aux->getDerecha() != nullptr) cola.altaCola(aux->getDerecha());
        }

        return os;
    }

    NodoArbolBinarioBusqueda<T>* insertarRecursivo(T ndato, NodoArbolBinarioBusqueda<T>* nodo){
        if (!nodo){
          //nodo == nullptr
            return new NodoArbolBinarioBusqueda(ndato);
        } else if (ndato < nodo->getDato()){
            nodo->setIzquierda(insertarRecursivo(ndato, nodo->getIzquierda()));
        } else if (ndato > nodo->getDato()){
            nodo->setDerecha(insertarRecursivo(ndato, nodo->getDerecha()));
        } else if (nodo->getDato() == ndato){
            std::cout << "El dato " << ndato << " ya existe.\n";
        }
        return nodo;
    }

    NodoArbolBinarioBusqueda<T>* insertarIterativo(T ndato, NodoArbolBinarioBusqueda<T>* nodo){
        NodoArbolBinarioBusqueda<T>* nuevo_nodo = new NodoArbolBinarioBusqueda<T>(ndato);
        NodoArbolBinarioBusqueda<T>* aux = nodo;

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

    NodoArbolBinarioBusqueda<T>* valorMinimo(NodoArbolBinarioBusqueda<T>* nodo){
        NodoArbolBinarioBusqueda<T>* aux = nodo;

        while (aux->getIzquierda() != nullptr){
            aux = aux->getIzquierda();
        }
        return aux;
    }

    NodoArbolBinarioBusqueda<T>* valorMaximo(NodoArbolBinarioBusqueda<T>* nodo){
        NodoArbolBinarioBusqueda<T>* aux = nodo;

        while (aux->getDerecha() != nullptr){
            aux = aux->getDerecha();
        }
        return aux;
    }

    virtual NodoArbolBinarioBusqueda<T>* eliminarRecursivo(T dato, NodoArbolBinarioBusqueda<T>* nodo){

        if (this->existe(dato)){
            if (nodo == nullptr) {
                return nodo;
            } else if (dato < nodo->getDato()){
                nodo->setIzquierda(eliminarRecursivo(dato, nodo->getIzquierda()));
            } else if (dato > nodo->getDato()){
                nodo->setDerecha(eliminarRecursivo(dato, nodo->getDerecha()));
            } else {
                NodoArbolBinarioBusqueda<T>* aux;
                if(nodo->getIzquierda() == nullptr){
                    aux = nodo->getDerecha();
                    delete nodo;
                    return aux;
                } else if (nodo->getDerecha() == nullptr){
                    aux = nodo->getIzquierda();
                    delete nodo;
                    return aux;
                } else {
//                  Minimo valor del sub-arbol derecho
                    aux = this->valorMinimo(nodo->getDerecha());
                    nodo->setDato(aux->getDato());
                    nodo->setDerecha(eliminarRecursivo(aux->getDato(), nodo->getDerecha()));

//                  Maximo valor del sub-arbol izquierdo
//                  aux = this->valorMaximo(nodo->getIzquierda());
//                  nodo->setDato(aux->getDato());
//                  nodo->setIzquierda(eliminarRecursivo(aux->getDato(), nodo->getIzquierda()));
                }
            }
        } else {
            std::cout << "El valor " << dato << " no existe en el arbol.\n";
        }
        return nodo;
    }

    bool existe(T dato){
        NodoArbolBinarioBusqueda<T>* aux = this->raiz;

        while (aux != nullptr && aux->getDato() != dato) {
            dato < aux->getDato() ? aux = aux->getIzquierda() : aux = aux->getDerecha();
        }

        return aux != nullptr;
    }

    NodoArbolBinarioBusqueda<T>* buscarNodo(T dato){
        NodoArbolBinarioBusqueda<T>* aux = this->raiz;

        while (aux != nullptr && aux->getDato() != dato) {
            dato < aux->getDato() ? aux = aux->getIzquierda() : aux = aux->getDerecha();
        }

        return aux;
    }

    void destruirNodo(NodoArbolBinarioBusqueda<T>* nodo){
        if(nodo != nullptr){
            destruirNodo(nodo->getIzquierda());
            destruirNodo(nodo->getDerecha());
            delete nodo;
        }
    }

    int calcularNodosIterativo(NodoArbolBinarioBusqueda<T>* nodo){
        int contador = 0;
        NodoArbolBinarioBusqueda<T>* aux = nodo;
        PilaDinamica<NodoArbolBinarioBusqueda<T>*> pila;

         if(aux != nullptr){
             pila.altaPila(aux);
             while(!pila.vaciaPila()){
                 aux = pila.obtenerPila();
                 contador++;
                 if (aux->getDerecha() != nullptr) pila.altaPila(aux->getDerecha());
                 if (aux->getIzquierda() != nullptr) pila.altaPila(aux->getIzquierda());
             }
         }
        return contador;
    }

    int calcularHojasRecursivo(NodoArbolBinarioBusqueda<T>* nodo){
        int contador = 0;
        if (nodo != nullptr){
            if (nodo->getIzquierda() == nullptr && nodo->getDerecha() == nullptr) return 1;
            contador += calcularHojasRecursivo(nodo->getIzquierda());
            contador += calcularHojasRecursivo(nodo->getDerecha());
        }
        return contador;
    }

    int calcularHojasIterativo(NodoArbolBinarioBusqueda<T>* nodo){
        int contador = 0;
        NodoArbolBinarioBusqueda<T>* aux = nodo;
        PilaDinamica<NodoArbolBinarioBusqueda<T>*> pila;

         if(aux != nullptr){
             pila.altaPila(aux);
             while(!pila.vaciaPila()){
                 aux = pila.obtenerPila();
                 if (aux->getDerecha() != nullptr) pila.altaPila(aux->getDerecha());
                 if (aux->getIzquierda() != nullptr) pila.altaPila(aux->getIzquierda());
                 if (aux->getIzquierda() == nullptr && aux->getDerecha() == nullptr) contador++;
             }
         }
        return contador;
    }

    int calcularAlturaRecursiva(NodoArbolBinarioBusqueda<T>* nodo){
        if (nodo == nullptr) {
            return -1;
        } else {
            int izq = calcularAlturaRecursiva(nodo->getIzquierda());
            int der = calcularAlturaRecursiva(nodo->getDerecha());
            return izq > der ? izq + 1 : der + 1;
        }
    }

    int calcularAlturaIterativa(NodoArbolBinarioBusqueda<T>* nodo){
        int altura = 0;

        if (nodo == nullptr) return altura;

        NodoArbolBinarioBusqueda<T>* aux = nodo;
        ColaDinamica<NodoArbolBinarioBusqueda<T>*> cola;
        int tamanioCola = 0;
        int cantNodos;

        cola.altaCola(aux);
        tamanioCola++;

        while (!cola.vaciaCola()){
            altura++;
            cantNodos = tamanioCola;

            while (cantNodos > 0){
                aux = cola.obtenerCola();
                tamanioCola--;
                cantNodos--;

                if (aux->getIzquierda() != nullptr) {
                    cola.altaCola(aux->getIzquierda());
                    tamanioCola++;
                }
                if (aux->getDerecha() != nullptr) {
                    cola.altaCola(aux->getDerecha());
                    tamanioCola++;
                }
            }
        }
        return altura;
    }

    bool completo(NodoArbolBinarioBusqueda<T>* nodo){
        ColaDinamica<NodoArbolBinarioBusqueda<T>*> cola;
        bool bandera = true;

        if (nodo != nullptr){
            cola.altaCola(nodo);
            while (!cola.vaciaCola() && bandera){
                nodo = cola.obtenerCola();
                if (nodo->getIzquierda() != nullptr && nodo->getDerecha() != nullptr){
                    cola.altaCola(nodo->getIzquierda());
                    cola.altaCola(nodo->getDerecha());
                } else if ((nodo->getIzquierda() != nullptr && nodo->getDerecha() == nullptr) || (nodo->getIzquierda() == nullptr && nodo->getDerecha() != nullptr)) {
                    bandera = false;
                }
            }
        }
        return bandera;
    }

    int nodosPorNiveles(NodoArbolBinarioBusqueda<T>* nodo, int nivel){
        if (nodo == nullptr) return 0;
        if (nivel == 0) return 1;
        return nodosPorNiveles(nodo->getIzquierda(), nivel - 1) + nodosPorNiveles(nodo->getDerecha(), nivel - 1);
    }

    void mostarHorizontal2D(NodoArbolBinarioBusqueda<T>* raiz, int cantEspacios) {
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

public:

    ArbolBinarioBusqueda(){
        this->raiz = nullptr;
    }

    ~ArbolBinarioBusqueda(){
        this->limpiar();
    }

    void limpiar(){
        this->destruirNodo(this->getRaiz());
        this->raiz = nullptr;
    }

    void virtual agregar(T ndato){
        this->raiz = this->insertarRecursivo(ndato, this->getRaiz());
    }

    friend std::ostream& operator<<(std::ostream& os, ArbolBinarioBusqueda<T>& arbol){
        if(arbol.getRaiz() != nullptr){
            return arbol.mostrarIterativoPreOrder(os, arbol.getRaiz());
        } else {
            os << "El arbol esta vacio.\n";
            return os;
        }
    } 

    void eliminarHojasEn0(){
        NodoArbolBinarioBusqueda<T>* aux = this->raiz;
        NodoArbolBinarioBusqueda<T>* padre;
        PilaDinamica<NodoArbolBinarioBusqueda<T>*> pila;

        if (aux != nullptr){
            pila.altaPila(aux);
            while (!pila.vaciaPila()){
                padre = aux;
                aux = pila.obtenerPila();

                if ((aux->getIzquierda() == nullptr && aux->getDerecha() == nullptr) && aux->getDato() == 0){
                    delete aux;
                    padre->getDerecha == 0 ? padre->setDerecha(nullptr) : padre->setIzquierda(nullptr);
                }

                if (aux->getDerecha() != nullptr) pila.altaPila(aux->getDerecha());
                if (aux->getIzquierda() != nullptr) pila.altaPila(aux->getIzquierda());
            }
        }
     }

    int cantidadNodosDescendientes(int codigo){
        NodoArbolBinarioBusqueda<T>* nodo = this->buscarNodo(codigo);
        return this->calcularNodosIterativo(nodo) - 1;
    }

    void completarArbol(){
        if (!this->completo(this->raiz)){
           NodoArbolBinarioBusqueda<T>* aux = this->raiz;
           NodoArbolBinarioBusqueda<T>* padre;
           PilaDinamica<NodoArbolBinarioBusqueda<T>*> pila;

           if (aux != nullptr){
               pila.altaPila(aux);
                while (!pila.vaciaPila()){
                   padre = aux;
                   aux = pila.obtenerPila();

                   if (aux->getIzquierda() == nullptr && aux->getDerecha() == nullptr){
                       if ((padre->getDerecha() != nullptr && padre->getIzquierda() == nullptr) || (padre->getDerecha() == nullptr && padre->getIzquierda() != nullptr))
                          this->agregar(aux->getDato() + padre->getDato());
                   }

                   if (aux->getDerecha() != nullptr) pila.altaPila(aux->getDerecha());
                   if (aux->getIzquierda() != nullptr) pila.altaPila(aux->getIzquierda());
               }
           }
        }
    }

    void estaCompleto(){
       this->completo(this->raiz) ? std::cout << "Esta COMPLETO\n" : std::cout << "Esta IMCOMPLETO\n";
    }

    int nodosPorNivel(int nivel){
        return this->nodosPorNiveles(this->raiz, nivel);
    }

    int calcularNodos(){
        return this->calcularNodosIterativo(this->raiz);
    }

    int calcularAltura(){
       return this->calcularAlturaIterativa(this->raiz);
    }

    int calcularHojas(){
        return this->calcularHojasIterativo(this->raiz);
    }

    const T& getMinimo(){
        NodoArbolBinarioBusqueda<T>* minimo = this->valorMinimo(this->raiz);
        return minimo->getDato();
    }

    const T& getMaximo(){
        NodoArbolBinarioBusqueda<T>* maximo = this->valorMaximo(this->raiz);
        return maximo->getDato();
    }

    void eliminar(T dato){
        this->raiz = this->eliminarRecursivo(dato, this->raiz);
    }

    NodoArbolBinarioBusqueda<T>* getRaiz() const{
        return this->raiz;
    }

    void setRaiz(NodoArbolBinarioBusqueda<T>* raiz){
        this->raiz = raiz;
    }

    void mostrar(int cantEspacios){
        this->mostarHorizontal2D(this->raiz, cantEspacios);
    }


    template <class U>
    friend class ArbolAVL;
};



#endif // ArbolBinarioBusqueda_H

