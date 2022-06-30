#include "agenda.h"

agenda::agenda(){}

void agenda::agregarCumpleanio(cumpleanio cumple){
    this->lista.agregar(cumple);
}

void agenda::eliminarCumpleanio(std::string nombre){
    for(int i = 0; i < this->lista.getTamanio(); i++){
        if(this->lista.en(i).getNombre() == nombre){
            this->lista.borrar(i);
        }
    }
}

Vector<cumpleanio> agenda::getPorDia(int dia){
    Vector<cumpleanio> listaDia;

    for(int i = 0; i < this->lista.getTamanio(); i++){
        if(this->lista.en(i).getDia() == dia){
            listaDia.agregar(this->lista.en(i));
        }
    }
    return listaDia;
}

Vector<cumpleanio> agenda::getPorMes(int mes){
    Vector<cumpleanio> listaMes;

    for(int i = 0; i < this->lista.getTamanio(); i++){
        if(this->lista.en(i).getMes() == mes){
            listaMes.agregar(this->lista.en(i));
        }
    }
    return listaMes;
}

void agenda::mostrarCumpleanios(Vector<cumpleanio> vector){

    for(int i = 0; i < vector.getTamanio(); i++){
        std::cout << vector.en(i).getNombre() << " - " << vector.en(i).getDia() << " - " << vector.en(i).getMes() << " - " << vector.en(i).getAnio() << std::endl;
    }

}

void agenda::mostrarCumpleanios(){

    for(int i = 0; i < this->lista.getTamanio(); i++){
        std::cout << this->lista.en(i).getNombre() << " - " << this->lista.en(i).getDia() << " - " << this->lista.en(i).getMes() << " - " << this->lista.en(i).getAnio() << std::endl;
    }

}


