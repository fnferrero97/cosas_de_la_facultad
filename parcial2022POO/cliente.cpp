#include "cliente.h"
#include <stdio.h>

Cliente::Cliente(){}

Cliente::Cliente(int nroCliente, Factura* factura){
    this->nroCliente = nroCliente;
    this->factura = factura;
}

int Cliente::getnroCliente() const{
    return this->nroCliente;
}

float Cliente::cobrar(){
    return this->factura->calcular();
}


