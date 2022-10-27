#ifndef SIMPLE_H
#define SIMPLE_H

#include "curso.h"

class Simple : public Curso{
public:
    Simple();
    Simple(char*, char*, char*, float);
    float calcularHoras();
};

#endif // SIMPLE_H
