#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <iostream>

template <class T>
class Vector{

private:
    T* vector = nullptr;
    int capacidad = 0;
    int tamanio = 0;


    void agrandarTamanio(int nCapacidad){
        T* aux = (T*)::operator new(nCapacidad * sizeof(T));

        if(nCapacidad < this->tamanio){
            this->tamanio = nCapacidad;
        }

        for(int i = 0; i < this->tamanio; i++){
            aux[i] = std::move(this->vector[i]);
        }

        for(int i = 0; i < this->tamanio; i++){
            this->vector[i].~T();
        }

        ::operator delete(this->vector, this->capacidad * sizeof(T));
        this->vector = aux;
        this->capacidad = nCapacidad;
    }

public:
    Vector(){
        this->agrandarTamanio(2);
    };

    ~Vector(){
        this->limpiar();
        ::operator delete(this->vector, this->capacidad * sizeof(T));
    }

    void virtual agregar(const T &ndato){

        if(this->tamanio >= this->capacidad){
            this->agrandarTamanio(this->capacidad*2);
        }

        this->vector[tamanio++] = ndato;
    }

    void virtual agregar(T &&ndato){

        if(this->tamanio >= this->capacidad){
            this->agrandarTamanio(this->capacidad*2);
        }

        this->vector[tamanio++] = std::move(ndato);
    }

    void eliminar(){
        if(this->getTamanio() > 0){
            this->tamanio--;
            this->vector[tamanio].~T();
        }
    }

    void borrar(int indice){
        try{
            if(indice <= this->getTamanio() && indice >= 0){
                for (int i = indice; i < this->getTamanio()-1; i++){
                    this->vector[i] = this->vector[i+1];
                }
                this->tamanio--;
                } else {
                    throw(indice);
                }
            }catch(int indice){
            std::cout << "El indice " << indice << " esta fuera del rango del vector." << std::endl;
        }
    }

    void limpiar(){
        for (int i = 0; i < this->getTamanio(); i++){
            this->vector[i].~T();
        }

        this->tamanio = 0;
    }

    bool vacio() const{
        return this->tamanio == 0;
    }

    T& en(int indice){
        try{
            if(indice <= this->getTamanio() && indice >= 0){
                return this->vector[indice];
            } else {
                throw(indice);
            }
        }catch(int indice){
            std::cout << "El indice " << indice << " esta fuera del rango del vector." << std::endl;
        }
    }

    T& primero(){
        return this->vector[0];
    }

    T& ultimo(){
        return this->vector[this->tamanio-1];
    }

    template <typename... Argumentos>
    T& emplazarAtras(Argumentos&&... args){

        if(this->tamanio >= this->capacidad){
            this->agrandarTamanio(this->capacidad*2);
        }

        new(&this->vector[this->tamanio]) T(std::forward<Argumentos>(args)...);

        return this->vector[this->tamanio++];
    }

    int getTamanio() const{
        return this->tamanio;
    }

    const T& operator[](int indice) const{
        return this->vector[indice];
    }

    T& operator[](int indice){
        return this->vector[indice];
    }

};
#endif // VECTOR_H
