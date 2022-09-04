#ifndef CIUDAD_H
#define CIUDAD_H

#include "lugar.h"

class ciudad : public lugar {
private:
    int poblacion;
public:
    ciudad();
    ciudad(char*, int);
    int calcularPoblacion();
};

#endif // CIUDAD_H
