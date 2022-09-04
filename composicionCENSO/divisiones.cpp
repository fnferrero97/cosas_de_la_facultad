#include "divisiones.h"

divisiones::divisiones(){}

divisiones::divisiones(char* nombre, int maxCantidad) : lugar(nombre){
    this->maxCantidad = maxCantidad;
    this->lugares = nullptr;
}

int divisiones::calcularPoblacion(){
    int poblacion = 0;

    for(int i = 0; i < this->cantidadActual; i++){
        poblacion += this->lugares[i].calcularPoblacion();
    }

    return poblacion;
}

void divisiones::agregarLugar(lugar* lug){
   lugar* aux = new lugar;


}
