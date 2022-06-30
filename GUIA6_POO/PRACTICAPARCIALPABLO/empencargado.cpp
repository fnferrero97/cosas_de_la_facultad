#include "empencargado.h"


EmpEncargado::EmpEncargado(std::string nombre, std::string apellido, long cuil, float sueldoFijo, int objetivoLogrado) : Empleado(nombre, apellido, cuil, sueldoFijo){
    this->objetivoLogrado = objetivoLogrado;
}

float EmpEncargado::calcularSueldo(){
    return this->getSueldoFijo() + this->getObjetivoLogrado() * 1000;
}

void EmpEncargado::getInfo(){
    Empleado::getInfo();
    std::cout << this->calcularSueldo();
}
int EmpEncargado::getObjetivoLogrado() const{
    return objetivoLogrado;
}

void EmpEncargado::setObjetivoLogrado(int newObjetivoLogrado){
    objetivoLogrado = newObjetivoLogrado;
}
