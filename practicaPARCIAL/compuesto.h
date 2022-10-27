#ifndef COMPUESTO_H
#define COMPUESTO_H
#include <vector>
#include "curso.h"
#include "simple.h"

class Compuesto : public Curso {
private:
    std::vector<Simple> listaCursos;
public:
    Compuesto();
    Compuesto(char*, char*, char*);
    float calcularHoras();
    void agregarCurso(Simple);
};

#endif // COMPUESTO_H
