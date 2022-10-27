#ifndef CORRELATIVO_H
#define CORRELATIVO_H
#include <vector>
#include "curso.h"

class Correlativo : public Curso {
private:
    std::vector<Curso*> listaCorrelativas;
public:
    Correlativo();
    Correlativo(char*, char*, char*, float);
    float calcularHoras();
    void agregarCorrelativas(Curso*);
};

#endif // CORRELATIVO_H
