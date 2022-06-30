#include "gastoextraordinario.h"

gastoExtraordinario::gastoExtraordinario(std::string detalle, float valor) : gasto(detalle, valor){}

void gastoExtraordinario::mostrarDetalle(){
    std::cout << "Gasto extraordinario \""<< this->getDetalle() << "\" ..............$ " << this->getValor() << std::endl;
}
