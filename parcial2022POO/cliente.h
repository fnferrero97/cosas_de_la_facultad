#ifndef CLIENTE_H
#define CLIENTE_H
#include "factura.h"


class Cliente {
private:
    int nroCliente;
    Factura* factura;
public:
    Cliente();
    Cliente(int, Factura*);
    int getnroCliente() const;
    float cobrar();
};

#endif // CLIENTE_H
