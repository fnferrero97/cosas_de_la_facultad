#ifndef FACTURAMIXTA_H
#define FACTURAMIXTA_H
#include "factura.h"

class FacturaMIXTA : public Factura{
private:
    int cantGigas;
    int cantHoras;
public:
    FacturaMIXTA();
    FacturaMIXTA(float, float, float, int, int);
    float calcular();
};

#endif // FACTURAMIXTA_H
