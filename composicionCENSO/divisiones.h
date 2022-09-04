#ifndef DIVISIONES_H
#define DIVISIONES_H

#include "lugar.h"

class divisiones : public lugar {
private:
    int maxCantidad;
    int cantidadActual = 0;
    lugar* lugares;
public:
    divisiones();
    divisiones(char*, int);
    int calcularPoblacion();
    void agregarLugar(lugar*);
    int getcantidadActual() const;
    void setCantidadActual(int CantidadActual);
};

#endif // DIVISIONES_H
