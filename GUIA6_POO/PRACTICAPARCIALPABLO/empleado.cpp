#include "empleado.h"


Empleado::Empleado(){}

Empleado::Empleado(std::string nombre, std::string apellido, long cuil, float sueldoFijo){
    this->nombre = nombre;
    this->apellido = apellido;
    this->cuil = cuil;
    this->sueldoFijo = sueldoFijo;
}

void Empleado::getInfo(){
    std::cout << this->getCuil() << " - " << this->getNombre() << " - " << this->getApellido() << " - ";
}

const std::string &Empleado::getNombre() const{
    return nombre;
}

void Empleado::setNombre(const std::string &newNombre){
    nombre = newNombre;
}

const std::string &Empleado::getApellido() const{
    return apellido;
}

void Empleado::setApellido(const std::string &newApellido){
    apellido = newApellido;
}

long Empleado::getCuil() const{
    return cuil;
}

void Empleado::setCuil(long newCuil){
    cuil = newCuil;
}

float Empleado::getSueldoFijo() const{
    return sueldoFijo;
}

void Empleado::setSueldoFijo(float newSueldoFijo){
    sueldoFijo = newSueldoFijo;
}
