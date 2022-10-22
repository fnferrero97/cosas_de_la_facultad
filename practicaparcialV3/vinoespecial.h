#ifndef VINOESPECIAL_H
#define VINOESPECIAL_H

#include "vinogeneral.h"

class vinoEspecial : public vinoGeneral{
public:
    vinoEspecial(int, float, char, int);
    float calcularPrecio();
    bool sePuedeVender(int);
    int getTipo();
};

#endif // VINOESPECIAL_H
