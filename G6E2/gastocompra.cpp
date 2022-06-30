#include "gastocompra.h"

gastoCompra::gastoCompra(std::string detalle, float valor) : gasto(detalle, valor){}

void gastoCompra::mostrarDetalle(){
    std::cout << "Gasto por compra de productos de " << this->getDetalle() << " ..............$ " << this->getValor() << std::endl;
}
