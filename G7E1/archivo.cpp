#include "archivo.h"
#include <iostream>


archivo::archivo(std::string nombre, std::string extension, float tamanio) : datas(nombre){
    this->extension = extension;
    this->tamanio = tamanio;
}

const std::string& archivo::getExtension() const{
    return extension;
}

float archivo::getTamanio() const{
    return tamanio;
}

float archivo::calcularTamanio(){
    return this->getTamanio();
}

void archivo::mostrarInfo(){
    std::cout << this->getNombre() << this->extension << " - " << this->tamanio << "kb\n";
}

//std::ostream& operator<<(std::ostream& os, archivo& archivo){
//    os << archivo.nombre << archivo.extension << std::to_string(archivo.tamanio);
//    return os;
//}
