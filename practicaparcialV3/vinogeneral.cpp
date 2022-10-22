#include "vinogeneral.h"


vinoGeneral::vinoGeneral(int nro, float litros, char tipo, int anioProduccion){
    this->nro = nro;
    this->tipo = tipo;
    this->litros = litros;
    this->anioProduccion = anioProduccion;
}

int vinoGeneral::getNro() const{
    return nro;
}

void vinoGeneral::setNro(int nro){
    this->nro = nro;
}

float vinoGeneral::getLitros() const{
    return this->litros;
}


void vinoGeneral::setLitros(float litros){
    this->litros = litros;
}

int vinoGeneral::getAnioProduccion() const{
    return anioProduccion;
}

void vinoGeneral::setAnioProduccion(int anioProduccion){
    this->anioProduccion = anioProduccion;
}
