            #ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <cstddef>
#include <iostream>
#include <string>


template <class T>
class ListaCircular{
private:
    T dato;
    ListaCircular* link;
public:
ListaCircular(){
    this->link = NULL;
}

ListaCircular* getLink() const{
    return this->link;
}

void setLink(ListaCircular* link){
    this->link = link;
}

const T& getDato() const{
    return this->dato;
}

void setDato(const T &dato){
    this->dato = dato;
}

bool vacia(){
    return this->link == NULL;
}

void agregarAtras(T ndato){
    ListaCircular* aux = this->link;
    ListaCircular* nuevo_nodo = new(ListaCircular);
    nuevo_nodo->dato = ndato;

    if(this->link != NULL){
        while(aux->link != this->link){
            aux = aux->link;
        }
        aux->link = nuevo_nodo;
    } else {
        this->link = nuevo_nodo;
    }
    nuevo_nodo->link = this->link;
}

void eliminarAtras(){

    if (this->link != NULL){
        if(this->link->link == this->link){
            this->link = NULL;
        } else {
            ListaCircular* aux = this->link;

            while(aux->link->link != this->link){
                aux = aux->link;
            }

            ListaCircular* eliminar = aux->link;
            delete eliminar;
            aux->link = this->link;
        }
    } else {
        std::cout << "La lista esta vacia.\n";
    }
}

void mostrar(){

    ListaCircular* aux = this->link;

    if(this->link == NULL){
        std::cout << "La lista esta vacia \n";
        return;
    } else {
        do {
            std::cout << "El dato es: " << aux->dato << ".\n";
            aux = aux->link;
        } while(aux->link != this->link);
    }
    if(aux != this->link){
    std::cout << "El dato es: " << aux->dato << ".\n";
    }
}

};
#endif // LISTACIRCULAR_H
