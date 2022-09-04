#ifndef NodoArbolBinarioBusqueda_H
#define NodoArbolBinarioBusqueda_H

template <class T>
class NodoArbolBinarioBusqueda{
private:
    T dato;
    NodoArbolBinarioBusqueda* izquierda = nullptr;
    NodoArbolBinarioBusqueda* derecha = nullptr;
public:
    NodoArbolBinarioBusqueda(T ndato){
        this->dato = ndato;
    }

    const T& getDato() const{
        return dato;
    }

    void setDato(const T& ndato){
        this->dato = ndato;
    }

    NodoArbolBinarioBusqueda* getIzquierda() const{
        return this->izquierda;
    }

    void setIzquierda(NodoArbolBinarioBusqueda* izquierda){
        this->izquierda = izquierda;
    }

    NodoArbolBinarioBusqueda* getDerecha() const{
        return this->derecha;
    }

    void setDerecha(NodoArbolBinarioBusqueda* derecha){
        this->derecha = derecha;
    }

};
#endif // NodoArbolBinarioBusqueda_H
