#include "empvendedor.h"


EmpVendedor::EmpVendedor(std::string nombre, std::string apellido, long cuil, float sueldoFijo, float montoVendido) : Empleado(nombre, apellido, cuil, sueldoFijo){
    this->montoVendido = montoVendido;
}

float EmpVendedor::calcularSueldo(){
    return this->getSueldoFijo() + this->getMontoVendido() * 0.02;
}

void EmpVendedor::getInfo(){
    Empleado::getInfo();
    std::cout << this->calcularSueldo();
}

float EmpVendedor::getMontoVendido() const{
    return montoVendido;
}

void EmpVendedor::setMontoVendido(float newMontoVendido){
    montoVendido = newMontoVendido;
}
