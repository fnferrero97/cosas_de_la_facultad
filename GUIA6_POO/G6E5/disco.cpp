#include "disco.h"


disco::disco(std::string nombre){
    this->nombre = nombre;
}

void disco::agregarCancion(cancion cancion){
    this->canciones.agregar(cancion);
}

void disco::mostrarCanciones(){
    std::cout << "El disco: " << this->getNombre() << " tiene las siguientes canciones: \n";

    for (int i = 0; i < this->canciones.getTamanio(); i++){
        std::cout << this->canciones[i].getNombre() << " - " <<this->canciones[i].getAutor() << "\n";
    }
}

const std::string& disco::getNombre() const{
    return nombre;
}

const Vector<cancion> &disco::getCanciones() const{
    return canciones;
}
