#include "gasto.h"


gasto::gasto(std::string detalle, float valor){
    this->detalle = detalle;
    this->valor = valor;
}

gasto::~gasto(){}


float gasto::getValor() const{
    return this->valor;
}

const std::string& gasto::getDetalle() const{
    return detalle;
}
