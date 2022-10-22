#ifndef VINOPREMIUM_H
#define VINOPREMIUM_H

#include "vinogeneral.h"

class vinoPremium : public vinoGeneral{
public:
    vinoPremium(int, float, char, int);
    float calcularPrecio();
    bool sePuedeVender(int);
    int getTipo();
};

#endif // VINOPREMIUM_H
