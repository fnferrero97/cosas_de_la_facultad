#ifndef ColaDinamica_H
#define ColaDinamica_H
#include "NodoColaDinamica"

template <class T>
class ColaDinamica{
private:
    NodoColaDinamica<T>* frente;
    NodoColaDinamica<T>* fondo;
public:
    ColaDinamica(){
        this->frente = nullptr;
        this->fondo = nullptr;
    }

    void altaCola(T ndato){
        NodoColaDinamica<T>* nuevo_nodo = new NodoColaDinamica<T>(ndato);

        if (frente == nullptr){
            frente = nuevo_nodo;
        } else {
            fondo->setLink(nuevo_nodo);
        }

        fondo = nuevo_nodo;
    }

    T obtenerCola(){
        T dato = frente->getDato();
        NodoColaDinamica<T>* aux = frente;

        if (frente == fondo){
            frente = nullptr;
            fondo = nullptr;
        } else {
            frente = frente->getLink();
        }

        delete aux;
        return dato;
    }

    bool vaciaCola(){
        return frente == nullptr && fondo == nullptr;
    }
};

#endif // ColaDinamica_H
