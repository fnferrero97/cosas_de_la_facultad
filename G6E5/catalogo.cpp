#include "catalogo.h"


catalogo::catalogo(std::string nombre){
    this->nombre = nombre;
}

void catalogo::agregarDisco(disco disco){
    this->articulos.agregar(disco);
}

const std::string &catalogo::getNombre() const{
    return nombre;
}


void catalogo::mostrarCatalogo(){

    std::cout << "El catalogo: " << this->getNombre() << " tiene estos discos con estas canciones: " << " \n";

    for (int i = 0; i < this->articulos.getTamanio(); i++){
        std::cout << this->articulos[i].getNombre() << "\n";
        this->articulos[i].mostrarCanciones();
        }
}
