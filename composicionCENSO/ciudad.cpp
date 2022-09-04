#include "ciudad.h"

ciudad::ciudad(){}

ciudad::ciudad(char* nombre, int poblacion) : lugar(nombre){
    this->poblacion = poblacion;
}

int ciudad::calcularPoblacion(){
    return this->poblacion;
}
