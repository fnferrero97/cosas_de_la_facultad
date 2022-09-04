#include "gestorclientes.h"

GestorClientes::GestorClientes(){}

void GestorClientes::agregarCliente(Cliente persona){
    Cliente* aux = new Cliente[this->cantCargados + 1];

    for (int i = 0; i < this->cantCargados; i++){
        aux[i] = this->clientes[i];
    }

    aux[this->cantCargados++] = persona;
    this->clientes = aux;
}

void GestorClientes::generarCobros(){
    for (int i = 0; i < this->cantCargados; i++){
        this->acumCobrar += this->clientes[i].cobrar();
    }
}

void GestorClientes::listarClientesDeudas(float deuda){
    for (int i = 0; i < this->cantCargados; i++){
        if (this->clientes[i].cobrar() > deuda)
        std::cout << "CLIENTE NRO: "<< this->clientes[i].getnroCliente() << " - " << this->clientes[i].cobrar() << "$\n";
    }
}

float GestorClientes::getacumCobrar() const{
    return acumCobrar;
}


