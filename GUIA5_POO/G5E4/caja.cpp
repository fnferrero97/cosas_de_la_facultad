#include "caja.h"
#include <iostream>

caja::caja(){}

void caja::calcularVueltoOptimo(int valor){
    try{
        if (valor > 0){
            for (int i = 0; i < 10; i++){
                if(this->valoresCaja[i] <= valor){
                    while(this->valoresCaja[i] <= valor){
                        this->vuelto.agregarElemento(this->valoresCaja[i]);
                        valor -= this->valoresCaja[i];
                    }
                }
            }
        } else {
            throw(valor);
        }
    }catch (int valor) {
        if(valor == 0)
           std::cout << "El valor es 0." << std::endl;
        if(valor < 0)
           std::cout << "El valor es negativo." << std::endl;
    }
}

void caja::mostrarVuelto(){
    if(this->vuelto.getCantElementos() > 0){
        this->vuelto.mostrarDatos();}
    else {
        std::cout << "No se requiere dar vuelto" << std::endl;
    }
}
