#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H
#include <iostream>
#define size 3

template <class T>
class ColaCircular{
private:
    T cola[size];
    int frente = -1;
    int fondo = -1;
public:
    ColaCircular(){};

    bool vacia(){
        if (this->frente == -1) return true;
        return false;
    };

    bool llena(){
        if (this->frente == 0 && this->fondo == size - 1) return true;
        if (this->frente == this->fondo +1) return true;
        return false;
    };

    void agregar(T ndato){
        if(this->llena()){
            std::cout << "No se pudo agregar, la cola esta llena.\n";
        } else {
            if(this->vacia()){
                this->frente = 0;
            }
            this->fondo = (this->fondo + 1) % size;
            this->cola[fondo] = ndato;
            std::cout << "El elemento fue ingresado.\n";
        }
    };

    void obtener(){
        T dato;
        if(this->vacia()){
            std::cout << "La cola esta vacia.\n";
        } else {
            dato = cola[this->frente];
            if(this->frente == this->fondo){
                this->frente = -1;
                this->fondo = -1;
            } else {
                frente = (frente + 1) % size;
            }
        }
        std::cout << "El dato es: " << dato << ".\n";
    };
};

#endif // COLACIRCULAR_H
