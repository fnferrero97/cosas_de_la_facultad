#include "facturatiempo.h"

FacturaTIEMPO::FacturaTIEMPO(){}

FacturaTIEMPO::FacturaTIEMPO(float mes, float tiempo, float giga, int cantHoras) : Factura((char*)"TIEMPO", mes, tiempo, giga){
    this->cantHoras = cantHoras;
}

float FacturaTIEMPO::calcular(){
    return this->getmontoxtiempo() * this->cantHoras;
}
