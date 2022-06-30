#include "pila.h"
#include <cstddef>


pila::pila() noexcept{
    this->link = NULL;
    this->cantElementos = 0;
}

void pila::alta_pila(int ndato){

    pila* nuevo_nodo = new(pila);
    nuevo_nodo->setDato(ndato);
    nuevo_nodo->setLink(this->link);
    this->link = nuevo_nodo;

    this->cantElementos++;
}

int pila::baja_pila(){

    int dato = this->link->getDato();
    pila* aux = this->getLink();
    this->link = aux->getLink();
    delete aux;

    this->cantElementos--;
    return dato;
}

bool pila::pila_vacia(){
    return this->cantElementos == 0;
}

int pila::getDato() const{
    return dato;
}

void pila::setDato(int ndato){
    this->dato = ndato;
}

void pila::setLink(pila* newLink){
    link = newLink;
}

pila* pila::getLink() const{
    return link;
}

