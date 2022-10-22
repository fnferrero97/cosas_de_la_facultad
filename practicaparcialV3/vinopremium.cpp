#include "vinopremium.h"

vinoPremium::vinoPremium(int nro, float litros, char tipo, int anioProduccion) : vinoGeneral(nro, litros, tipo, anioProduccion){}

float vinoPremium::calcularPrecio(){
    return 200 * this->getLitros();
}

bool vinoPremium::sePuedeVender(int anio){
    return anio - this->getAnioProduccion() > 1;
}

int vinoPremium::getTipo(){
    return 2;
}
