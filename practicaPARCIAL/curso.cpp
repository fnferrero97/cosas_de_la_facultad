#include "curso.h"


Curso::Curso(){}

Curso::Curso(char* codigoAN, char* nombre, char* temaRelacionado, float cantHorasAsignadas){
    this->codigoAN = codigoAN;
    this->nombre = nombre;
    this->temaRelacionado = temaRelacionado;
    this->cantHorasAsignadas = cantHorasAsignadas;
}

char *Curso::getCodigoAN() const{
    return codigoAN;
}

void Curso::setCodigoAN(char *codigoAN){
    this->codigoAN = codigoAN;
}

char *Curso::getNombre() const{
    return nombre;
}

void Curso::setNombre(char *nombre){
    this->nombre = nombre;
}

char *Curso::getTemaRelacionado() const{
    return temaRelacionado;
}

void Curso::setTemaRelacionado(char *temaRelacionado){
    this->temaRelacionado = temaRelacionado;
}

float Curso::getCantHorasAsignadas() const{
    return cantHorasAsignadas;
}

void Curso::setCantHorasAsignadas(float cantHorasAsignadas){
    this->cantHorasAsignadas = cantHorasAsignadas;
}

std::ostream& operator<<(std::ostream& os, Curso& curso){
    os << curso.getCodigoAN() << " - " << curso.getNombre();
    return os;
}


