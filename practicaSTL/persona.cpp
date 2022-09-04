#include "persona.h"

Persona::Persona(){}

Persona::Persona(char* nombre, char* apellido, long telefono){
    this->nombre = nombre;
    this->apellido = apellido;
    this->telefono = telefono;
}

char* Persona::getNombre() const{
    return nombre;
}

void Persona::setNombre(char *nombre){
    this->nombre = nombre;
}

char *Persona::getApellido() const{
    return apellido;
}

void Persona::setApellido(char *apellido){
    this->apellido = apellido;
}

long Persona::getTelefono() const{
    return telefono;
}

void Persona::setTelefono(long telefono){
    this->telefono = telefono;
}

std::ostream& operator<<(std::ostream& os, Persona& otro){
    os << "# Nombre: " << otro.getNombre() << " - Apellido: " << otro.getApellido() << " - TEL: " << otro.getTelefono() << "\n";
    return os;
}

