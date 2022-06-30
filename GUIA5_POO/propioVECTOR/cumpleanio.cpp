#include "cumpleanio.h"

cumpleanio::cumpleanio(int dia, int mes, int anio, std::string nombre){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->nombre = nombre;
}

int cumpleanio::getDia() const{
    return this->dia;
}

int cumpleanio::getMes() const{
    return this->mes;
}

int cumpleanio::getAnio() const{
    return this->anio;
}

std::string cumpleanio::getNombre() const{
    return this->nombre;
}

cumpleanio::~cumpleanio(){}
