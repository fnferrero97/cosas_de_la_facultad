#ifndef GESTORGASTOS_H
#define GESTORGASTOS_H
#include "vector.h"
#include "gasto.h"

class gestorGastos{
private:
    Vector<gasto*> lista;
public:
    gestorGastos();
    ~gestorGastos();
    void listarGastos();
    void agregarGasto(gasto*);
    void calculaTotales();
};

#endif // GESTORGASTOS_H
