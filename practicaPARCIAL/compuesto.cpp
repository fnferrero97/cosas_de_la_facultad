#include "compuesto.h"

Compuesto::Compuesto() : Curso(){}

Compuesto::Compuesto(char* codigoAN, char* nombre, char* temaRelacionado) : Curso(codigoAN, nombre, temaRelacionado){}

float Compuesto::calcularHoras(){
    float acum = 0;

    for (Simple curso : this->listaCursos){
        acum += curso.calcularHoras();
    }

    return acum;
}

void Compuesto::agregarCurso(Simple otroCurso){
    this->listaCursos.push_back(otroCurso);
}
