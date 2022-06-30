#include "carta.h"

carta::carta(){}

carta::carta(std::string palo, int valor){
    this->palo = palo;
    this->valor = valor;
}

carta::~carta(){}

const std::string& carta::getPalo() const{
    return palo;
}

void carta::setPalo(const std::string &palo){
    this->palo = palo;
}

int carta::getValor() const{
    return valor;
}

void carta::setValor(int valor){
    this->valor = valor;
}

