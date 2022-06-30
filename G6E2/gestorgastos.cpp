#include "gestorgastos.h"

gestorGastos::gestorGastos(){}

gestorGastos::~gestorGastos(){
    this->lista.limpiar();
}

void gestorGastos::agregarGasto(gasto* gasto){
    this->lista.agregar(gasto);
}

void gestorGastos::calculaTotales(){
    int acumulador = 0;

    for (int i = 0; i < this->lista.getTamanio(); i++){
        acumulador += this->lista[i]->getValor();
    }

    std::cout << "El total de los gastos es de: " << acumulador <<"\n";
}

void gestorGastos::listarGastos(){
    try{
        if(this->lista.getTamanio() > 0){
            for(int i = 0; i < this->lista.getTamanio(); i++){
                this->lista.en(i)->mostrarDetalle();
            }
        } else {
            throw(-1);
        }
    } catch(...){
        std::cout << "La lista esta vacia." << std::endl;
    }
}
