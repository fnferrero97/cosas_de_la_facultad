#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include <iostream>
#include <ostream>
#include "nodoarbolbinario.h"
#include "pila.h"
#include "cola.h"

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

    NodoArbolBinario<T>* eliminarRecursivo(T dato, NodoArbolBinario<T>* nodo){

        if (this->existe(dato)){
            if (nodo == nullptr) {
                return nodo;
            } else if (dato < nodo->getDato()){
                nodo->setIzquierda(eliminarRecursivo(dato, nodo->getIzquierda()));
            } else if (dato > nodo->getDato()){
                nodo->setDerecha(eliminarRecursivo(dato, nodo->getDerecha()));
            } else {
                NodoArbolBinario<T>* aux;
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
        NodoArbolBinario<T>* aux = this->raiz;

        while (aux != nullptr && aux->getDato() != dato) {
            dato < aux->getDato() ? aux = aux->getIzquierda() : aux = aux->getDerecha();
        }

        return aux != nullptr;
    }

    NodoArbolBinario<T>* buscarNodo(T dato){
        NodoArbolBinario<T>* aux = this->raiz;

        while (aux != nullptr && aux->getDato() != dato) {
            dato < aux->getDato() ? aux = aux->getIzquierda() : aux = aux->getDerecha();
        }

        return aux;
    }

    void destruirNodo(NodoArbolBinario<T>* nodo){
        if(nodo != nullptr){
            destruirNodo(nodo->getIzquierda());
            destruirNodo(nodo->getDerecha());
            delete nodo;
        }
    }

    int calcularNodosIterativo(NodoArbolBinario<T>* nodo){
        int contador = 0;
        NodoArbolBinario<T>* aux = nodo;
        Pila<NodoArbolBinario<T>*> pila;

         if(aux != nullptr){
             pila.alta_pila(aux);
             while(!pila.pila_vacia()){
                 aux = pila.obtener_pila();
                 contador++;
                 if (aux->getDerecha() != nullptr) pila.alta_pila(aux->getDerecha());
                 if (aux->getIzquierda() != nullptr) pila.alta_pila(aux->getIzquierda());
             }
         }
        return contador;
    }

    int calcularHojasRecursivo(NodoArbolBinario<T>* nodo){
        int contador = 0;
        if (nodo != nullptr){
            if (nodo->getIzquierda() == nullptr && nodo->getDerecha() == nullptr) return 1;
            contador += calcularHojasRecursivo(nodo->getIzquierda());
            contador += calcularHojasRecursivo(nodo->getDerecha());
        }
        return contador;
    }

    int calcularHojasIterativo(NodoArbolBinario<T>* nodo){
        int contador = 0;
        NodoArbolBinario<T>* aux = nodo;
        Pila<NodoArbolBinario<T>*> pila;

         if(aux != nullptr){
             pila.alta_pila(aux);
             while(!pila.pila_vacia()){
                 aux = pila.obtener_pila();
                 if (aux->getDerecha() != nullptr) pila.alta_pila(aux->getDerecha());
                 if (aux->getIzquierda() != nullptr) pila.alta_pila(aux->getIzquierda());
                 if (aux->getIzquierda() == nullptr && aux->getDerecha() == nullptr) contador++;
             }
         }
        return contador;
    }

    int calcularAlturaRecursiva(NodoArbolBinario<T>* nodo){
        int a = 0;
        int b = 0;

        if (nodo == nullptr) return 0;
        if (nodo->getIzquierda() == nullptr && nodo->getDerecha() == nullptr) return 1;
        else {
            if (nodo->getIzquierda() != nullptr) a = 1 + calcularAlturaRecursiva(nodo->getIzquierda());
            if (nodo->getDerecha() != nullptr)   b = 1 + calcularAlturaRecursiva(nodo->getDerecha());
        }
        return a >= b ? a : b;
    }

//    if (nodo == nullptr) return 0;

//    NodoArbolBinario<T>* aux = nodo;
//    Cola<NodoArbolBinario<T>*> cola;
//    int altura = 0;
//    int cantNodos;
//    int tamanioCola = 0;

//    cola.alta(aux);
//    tamanioCola++;

//    while(1){
//        cantNodos = tamanioCola;
//        if(cantNodos == 0) return altura;
//        altura++;

//        while(cantNodos > 0){
//            aux = cola.obtener();
//            tamanioCola--;
//            if (aux->getIzquierda() != nullptr){
//                cola.alta(aux->getIzquierda());
//                tamanioCola++;
//            }
//            if (aux->getDerecha() != nullptr){
//                cola.alta(aux->getDerecha());
//                tamanioCola++;
//            }
//            cantNodos--;

    int calcularAlturaIterativa(NodoArbolBinario<T>* nodo){
        int altura = 0;

        if (nodo == nullptr) return altura;

        NodoArbolBinario<T>* aux = nodo;
        Cola<NodoArbolBinario<T>*> cola;
        int tamanioCola = 0;
        int cantNodos;

        cola.alta(aux);
        tamanioCola++;

        while (!cola.vacia()){
            altura++;
            cantNodos = tamanioCola;

            while (cantNodos > 0){
                aux = cola.obtener();
                tamanioCola--;
                cantNodos--;

                if (aux->getIzquierda() != nullptr) {
                    cola.alta(aux->getIzquierda());
                    tamanioCola++;
                }
                if (aux->getDerecha() != nullptr) {
                    cola.alta(aux->getDerecha());
                    tamanioCola++;
                }
            }
        }
        return altura;
    }

    bool completo(NodoArbolBinario<T>* nodo){
        Cola<NodoArbolBinario<T>*> cola;
        bool bandera = true;

        if (nodo != nullptr){
            cola.alta(nodo);
            while (!cola.vacia() && bandera){
                nodo = cola.obtener();
                if (nodo->getIzquierda() != nullptr && nodo->getDerecha() != nullptr){
                    cola.alta(nodo->getIzquierda());
                    cola.alta(nodo->getDerecha());
                } else if ((nodo->getIzquierda() != nullptr && nodo->getDerecha() == nullptr) || (nodo->getIzquierda() == nullptr && nodo->getDerecha() != nullptr)) {
                    bandera = false;
                }
            }
        }
        return bandera;
    }

    int nodosPorNiveles(NodoArbolBinario<T>* nodo, int nivel){
        if (nodo == nullptr) return 0;
        if (nivel == 0) return 1;
        return nodosPorNiveles(nodo->getIzquierda(), nivel - 1) + nodosPorNiveles(nodo->getDerecha(), nivel - 1);
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
            return arbol.mostrarIterativoPreOrder(os, arbol.getRaiz());
        } else {
            os << "El arbol esta vacio.\n";
            return os;
        }
    } 

    void eliminarHojasEn0(){
        NodoArbolBinario<T>* aux = this->raiz;
        NodoArbolBinario<T>* padre;
        Pila<NodoArbolBinario<T>*> pila;

        if (aux != nullptr){
            pila.alta_pila(aux);
            while (!pila.pila_vacia()){
                padre = aux;
                aux = pila.obtener_pila();

                if ((aux->getIzquierda() == nullptr && aux->getDerecha() == nullptr) && aux->getDato() == 0){
                    delete aux;
                    padre->getDerecha == 0 ? padre->setDerecha(nullptr) : padre->setIzquierda(nullptr);
                }

                if (aux->getDerecha() != nullptr) pila.alta_pila(aux->getDerecha());
                if (aux->getIzquierda() != nullptr) pila.alta_pila(aux->getIzquierda());
            }
        }
     }

    int cantidadNodosDescendientes(int codigo){
        NodoArbolBinario<T>* nodo = this->buscarNodo(codigo);
        return this->calcularNodosIterativo(nodo) - 1;
    }

    void completarArbol(){
        if (!this->completo(this->raiz)){
           NodoArbolBinario<T>* aux = this->raiz;
           NodoArbolBinario<T>* padre;
           Pila<NodoArbolBinario<T>*> pila;

           if (aux != nullptr){
               pila.alta_pila(aux);
                while (!pila.pila_vacia()){
                   padre = aux;
                   aux = pila.obtener_pila();

                   if (aux->getIzquierda() == nullptr && aux->getDerecha() == nullptr){
                       if ((padre->getDerecha() != nullptr && padre->getIzquierda() == nullptr) || (padre->getDerecha() == nullptr && padre->getIzquierda() != nullptr))
                          this->agregar(aux->getDato() + padre->getDato());
                   }

                   if (aux->getDerecha() != nullptr) pila.alta_pila(aux->getDerecha());
                   if (aux->getIzquierda() != nullptr) pila.alta_pila(aux->getIzquierda());
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
        NodoArbolBinario<T>* minimo = this->valorMinimo(this->raiz);
        return minimo->getDato();
    }

    const T& getMaximo(){
        NodoArbolBinario<T>* maximo = this->valorMaximo(this->raiz);
        return maximo->getDato();
    }

    void eliminarValor(T dato){
        this->raiz = this->eliminarRecursivo(dato, this->raiz);
    }

    NodoArbolBinario<T>* getRaiz() const{
        return this->raiz;
    }


};

#endif // ARBOLBINARIO_H

