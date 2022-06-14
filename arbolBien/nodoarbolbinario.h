#ifndef NODOARBOLBINARIO_H
#define NODOARBOLBINARIO_H

template <class T>
class NodoArbolBinario{
private:
    T dato;
    NodoArbolBinario* izquierda = nullptr;
    NodoArbolBinario* derecha = nullptr;
public:
    NodoArbolBinario(T ndato){
        this->dato = ndato;
    }

    const T& getDato() const{
        return dato;
    }

    void setDato(const T& ndato){
        this->dato = ndato;
    }

    NodoArbolBinario* getIzquierda() const{
        return this->izquierda;
    }

    void setIzquierda(NodoArbolBinario* izquierda){
        this->izquierda = izquierda;
    }

    NodoArbolBinario* getDerecha() const{
        return this->derecha;
    }

    void setDerecha(NodoArbolBinario* derecha){
        this->derecha = derecha;
    }

};
#endif // NODOARBOLBINARIO_H
