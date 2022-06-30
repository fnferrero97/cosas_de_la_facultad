#include "composicionautor_disco.h"

composicionAutor_Disco::composicionAutor_Disco(std::string nombre){
    this->nombre = nombre;
}


void composicionAutor_Disco::agregarCancion(cancion cancion){
    this->canciones.agregar(cancion);
}

void composicionAutor_Disco::mostrarCanciones(){
    for (int i = 0; i < this->canciones.getTamanio(); i++){
        std::cout << this->canciones[i].getNombre() << " - " <<this->canciones[i].getAutor();
    }
}
