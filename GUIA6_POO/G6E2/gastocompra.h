#ifndef GASTOCOMPRA_H
#define GASTOCOMPRA_H
#include "gasto.h"


class gastoCompra : public gasto{
public:
    gastoCompra(std::string, float);
    void mostrarDetalle();
};

#endif // GASTOCOMPRA_H
