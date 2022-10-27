#include "simple.h"

Simple::Simple() : Curso(){}

Simple::Simple(char* codigoAN, char* nombre, char* temaRelacionado, float cantHorasAsignadas) : Curso(codigoAN, nombre, temaRelacionado, cantHorasAsignadas){}

float Simple::calcularHoras(){
    return this->getCantHorasAsignadas();
}

