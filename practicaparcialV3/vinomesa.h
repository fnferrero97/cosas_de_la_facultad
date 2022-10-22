#ifndef VINOMESA_H
#define VINOMESA_H

#include "vinogeneral.h"

class vinoMesa : public vinoGeneral{
public:
    vinoMesa(int, float, char, int);
    float calcularPrecio();
    bool sePuedeVender(int);
    int getTipo();
};

#endif // VINOMESA_H
