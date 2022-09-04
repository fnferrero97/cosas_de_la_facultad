#ifndef FACTURAGIGA_H
#define FACTURAGIGA_H
#include "factura.h"

class FacturaGIGA : public Factura{
private:
    int cantGigas;
public:
    FacturaGIGA();
    FacturaGIGA(float, float, float, int);
    float calcular();
};

#endif // FACTURAGIGA_H
