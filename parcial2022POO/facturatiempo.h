#ifndef FACTURATIEMPO_H
#define FACTURATIEMPO_H
#include "factura.h"

class FacturaTIEMPO : public Factura{
    int cantHoras;
public:
    FacturaTIEMPO();
    FacturaTIEMPO(float, float, float, int);
    float calcular();
};

#endif // FACTURATIEMPO_H
