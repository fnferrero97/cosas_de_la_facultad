#include "autor.h"

autor::autor(){}

autor::autor(std::string nombre){
    this->nombre = nombre;
}

void autor::agregarCancion(cancion cancion){
    this->canciones.agregar(cancion);
}

const std::string &autor::getNombre() const{
    return nombre;
}

void autor::mostrarCanciones(){
    std::cout << "El autor: " << this->nombre << " tiene estas canciones: \n";

    for (int i = 0; i < this->canciones.getTamanio(); i++){
        std::cout << this->canciones[i].getNombre() << " - " <<this->canciones[i].getAutor() << "\n";
    }
}
