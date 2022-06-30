#include "cola.h"
#include <cstddef>



cola::cola(){
    this->frente = NULL;
    this->fondo = NULL;
    this->cantElementos = 0;
}

void cola::alta_cola(int ndato){

    cola* nueva_cola = new(cola);
    nueva_cola->setDato(ndato);
    nueva_cola->setLink(NULL);

    if (this->frente == NULL){
        this->frente = nueva_cola;
    } else {
        this->fondo->setLink(nueva_cola);
    }

    this->fondo = nueva_cola;
    this->cantElementos++;
}

int cola::baja_cola(){

    int dato = this->frente->getDato();
    cola* aux = this->frente;

    if (this->frente == this->fondo){
        this->frente = NULL;
        this->fondo = NULL;
    } else {
        this->frente = this->frente->getLink();
    }

    delete aux;

    this->cantElementos--;
    return dato;
}

bool cola::cola_vacia(){
    return this->cantElementos == 0;
}

int cola::getDato() const{
    return dato;
}

void cola::setDato(int newDato){
    dato = newDato;
}

cola *cola::getLink() const{
    return link;
}

void cola::setLink(cola* newLink){
    link = newLink;
}
