#include "gastoservicio.h"

gastoServicio::gastoServicio(std::string detalle, float valor) : gasto(detalle, valor){}

void gastoServicio::mostrarDetalle(){
    std::cout << "Gasto por servicio de la compania \"" << this->getDetalle() << "\" ..............$ " << this->getValor() << std::endl;
}
