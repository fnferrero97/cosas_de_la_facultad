#ifndef VECTORDINAMICO_H
#define VECTORDINAMICO_H
#include <iostream>

template <class T>
class VectorDinamico{
private:
    T* vd;
    int tamanio;
    int cantElementos;
public:

VectorDinamico<T>(){
    vd = new T[10];
    this->tamanio = 10;
    this->cantElementos = 0;
}

void agregarElemento(T ndato){
    if(this->cantElementos >= this->tamanio){
       this->aumentarTamanio();
    }

    this->vd[cantElementos++] = ndato;
}

void quitarElemento(int posicion){

    try{
        if(posicion > 0 && posicion <= this->cantElementos){
            T* aux = new T[this->tamanio-1];
            int j = 0;

            for (int i = 0; i < this->cantElementos; i++){
                if(i != posicion-1){
                    aux[j] = this->vd[i];
                    j++;
                }
            }
            this->cantElementos--;
            delete[] this->vd;
            this->vd = aux;
        } else {
            throw(posicion);
        }
    } catch(int posicion){
        std::cout << "La posicion " << posicion << " NO existe en el arreglo" << std::endl;
    }
}

int mayorElemento(){
    int mayor = this->vd[0];
    for (int i = 1; i < this->cantElementos; i++){
        if(this->vd[i] > mayor){
            mayor = this->vd[i];
        }
    }
    return mayor;
}

int menorElemento(){
    int menor = this->vd[0];
    for (int i = 1; i < this->cantElementos; i++){
        if(this->vd[i] < menor){
            menor = this->vd[i];
        }
    }
    return menor;
}

float getPromedio(){
    int acumulador = 0;
    for (int i = 0; i < this->cantElementos; i++){
        acumulador += this->vd[i];
    }

    return (float)acumulador / float(this->cantElementos);
}

void mostrarDatos(){
    std::cout << "[";
    for (int i = 0; i < this->cantElementos-1; i++){
        std::cout << this->vd[i] << ", ";
    }
    std::cout << this->vd[this->cantElementos-1] << "]";
}

void inicializar(int inicio){
    for (int i = inicio; i < this->tamanio; i++){
        this->vd[i] = 0;
    }
}

void aumentarTamanio(){
    this->tamanio *= 2;
    T* aux = new T[tamanio];

    for (int i = 0; i < this->cantElementos; i++){
        aux[i] = this->vd[i];
    }

    delete[] this->vd;
    this->vd = aux;
    inicializar(this->cantElementos);
}

int getCantElementos(){
    return cantElementos;
}

~VectorDinamico(){
    delete[] this->vd;
}

};
#endif // VECTORDINAMICO_H

