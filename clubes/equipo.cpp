#include "equipo.h"


Equipo::Equipo(){}

Equipo::Equipo(std::string nombre, int id){
    this->nombre = nombre;
    this->id = id;
}

std::string &Equipo::getNombre(){
    return nombre;
}

void Equipo::setNombre(const std::string &newNombre){
    nombre = newNombre;
}

int Equipo::getId() const{
    return id;
}

void Equipo::setId(int newId){
    id = newId;
}

//Equipo& Equipo::operator=(Equipo& otro){
//    id = otro.id;
//    nombre = otro.nombre;
//    return *this;
//}
