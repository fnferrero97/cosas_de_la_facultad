#include "vinomesa.h"

vinoMesa::vinoMesa(int nro, float litros, char tipo, int anioProduccion) : vinoGeneral(nro, litros, tipo, anioProduccion){}

float vinoMesa::calcularPrecio(){
    return 120 * this->getLitros();
}

bool vinoMesa::sePuedeVender(int anio){
    return anio - this->getAnioProduccion() > 0;
}

int vinoMesa::getTipo(){
    return 1;
}
