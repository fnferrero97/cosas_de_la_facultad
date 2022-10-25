#include "empleado.h"


Empleado::Empleado(){}

Empleado::Empleado(std::string dni, std::string nombre, std::string apellido, int horasTrabajadas){
    this->dni = dni;
    this->nombre = nombre;
    this->apellido = apellido;
    this->horasTrabajadas = horasTrabajadas;
}

int Empleado::getHorasTrabajadas() const{
    return horasTrabajadas;
}

void Empleado::setHorasTrabajadas(int horasTrabajadas){
    this->horasTrabajadas = horasTrabajadas;
}

const std::string &Empleado::getDni() const{
    return dni;
}

void Empleado::setDni(const std::string &dni){
    this->dni = dni;
}

const std::string &Empleado::getNombre() const{
    return nombre;
}

void Empleado::setNombre(const std::string &nombre){
    this->nombre = nombre;
}

const std::string &Empleado::getApellido() const{
    return apellido;
}

void Empleado::setApellido(const std::string &apellido){
    this->apellido = apellido;
}
