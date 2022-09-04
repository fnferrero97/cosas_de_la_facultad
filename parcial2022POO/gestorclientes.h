#ifndef GESTORCLIENTES_H
#define GESTORCLIENTES_H
#include "cliente.h"
#include <iostream>

class GestorClientes {
private:
    Cliente* clientes;
    int cantCargados = 0;
    float acumCobrar = 0.0;
public:
    GestorClientes();
    void agregarCliente(Cliente);
    void generarCobros();
    void listarClientesDeudas(float);
    float getacumCobrar() const;
};

#endif // GESTORCLIENTES_H
