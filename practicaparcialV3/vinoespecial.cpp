#include "vinoespecial.h"

vinoEspecial::vinoEspecial(int nro, float litros, char tipo, int anioProduccion) : vinoGeneral(nro, litros, tipo, anioProduccion){}

float vinoEspecial::calcularPrecio(){
    return 320 * this->getLitros();
}

bool vinoEspecial::sePuedeVender(int anio){
    return anio - this->getAnioProduccion() > 2;
}

int vinoEspecial::getTipo(){
    return 3;
}
