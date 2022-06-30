#include "empnormal.h"

EmpNormal::EmpNormal(std::string nombre, std::string apellido, long cuil, float sueldoFijo) : Empleado(nombre, apellido, cuil, sueldoFijo){}

float EmpNormal::calcularSueldo(){
    return this->getSueldoFijo();
}

void EmpNormal::getInfo(){
    Empleado::getInfo();
    std::cout << this->calcularSueldo();
}
