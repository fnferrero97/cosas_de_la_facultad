#include "facturagiga.h"

FacturaGIGA::FacturaGIGA(){}

FacturaGIGA::FacturaGIGA(float mes, float tiempo, float giga, int cantGigas) : Factura((char*)"GIGA", mes, tiempo, giga){
    this->cantGigas = cantGigas;
}

float FacturaGIGA::calcular(){
    return this->getmontoxgiga() * this->cantGigas;
}
