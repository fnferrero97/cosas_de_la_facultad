#include "cancion.h"

cancion::cancion(){}

cancion::cancion(std::string nombre, class autor* autor){
    this->nombre = nombre;
    this->autor = autor;
}

const std::string& cancion::getNombre() const{
    return nombre;
}

void cancion::setNombre(const std::string &nombre){
    this->nombre = nombre;
}

const std::string& cancion::getAutor() const{
    return this->autor->getNombre();
}

void cancion::setAutor(class autor* autor){
    this->autor = autor;
}
