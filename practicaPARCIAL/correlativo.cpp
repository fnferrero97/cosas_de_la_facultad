#include "correlativo.h"

Correlativo::Correlativo() : Curso(){}

Correlativo::Correlativo(char* codigoAN, char* nombre, char* temaRelacionado, float cantHorasAsignadas) : Curso(codigoAN, nombre, temaRelacionado, cantHorasAsignadas){}

float Correlativo::calcularHoras(){
    float acum = 0;

    for (Curso* curso : this->listaCorrelativas){
        acum += curso->calcularHoras();
    }

    return acum + this->getCantHorasAsignadas();
}

void Correlativo::agregarCorrelativas(Curso* otroCurso){
    this->listaCorrelativas.push_back(otroCurso);
}
