#ifndef CAJA_H
#define CAJA_H
#include "vectordinamico.h"


class caja{
private:
    VectorDinamico<int> vuelto;
    int valoresCaja[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
public:
    caja();
    void calcularVueltoOptimo(int);
    void mostrarVuelto();
};

#endif // CAJA_H
