#ifndef ArbolB_H
#define ArbolB_H
#include "NodoArbolB.h"

template <class U>
class ArbolB {
private:
    NodoArbolB<U>* raiz;
    int orden;
public:
    ArbolB();

    ArbolB(int orden){
        this->raiz = nullptr;
        this->orden = orden;
    }

    void recorrer(){
        if (this->raiz != nullptr) this->raiz->recorrer();
    }

    NodoArbolB<U>* buscar(U dato){
        this->raiz == nullptr ? nullptr : this->raiz->buscar(dato);
    }

    void agregar(U dato){
        if (this->raiz == nullptr){
            this->raiz = new NodoArbolB<U>(this->orden, true);
            this->raiz->claves[0] = dato;
            this->raiz->cantActualClaves = 1;
        } else {
            if (this->raiz->cantActualClaves == 2 * this->orden - 1){
                NodoArbolB<U>* nuevoNodo = new NodoArbolB<U>(this->orden, false);
                nuevoNodo->hijos[0] = this->raiz;
                nuevoNodo->partirMitad(0, this->raiz);

                int i = 0;
                if (nuevoNodo->claves[0] < dato) i++;
                nuevoNodo->hijos[i]->agregarNoLleno(dato);
                this->raiz = nuevoNodo;
            } else {
                this->raiz->agregarNoLleno(dato);
            }
        }
    }

    void eliminar(U dato){
            if (this->raiz == nullptr){
                std::cout << "El arbol B esta vacio\n";
                return;
            }

            this->raiz->eliminar(dato);

            if (this->raiz->cantActualClaves == 0){
               NodoArbolB<U>* aux = this->raiz;
               this->raiz->hoja ? this->raiz = nullptr   : this->raiz = this->raiz->hijos[0];

               delete aux;
            }
            return;
        }
};


#endif // ArbolB_H
