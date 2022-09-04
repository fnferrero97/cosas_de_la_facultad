#include "facturamixta.h"

FacturaMIXTA::FacturaMIXTA(){}

FacturaMIXTA::FacturaMIXTA(float mes, float tiempo, float giga, int cantHoras, int cantGigas) : Factura((char*)"MIXTA", mes, tiempo, giga){
    this->cantHoras = cantHoras;
    this->cantGigas = cantGigas;
}

float FacturaMIXTA::calcular(){
    float menor;
    float valorGigas = this->getmontoxgiga() * this->cantGigas;
    float valorHoras = this->getmontoxtiempo() * this->cantHoras;

    if (this->getmontoxmes() <= valorGigas && this->getmontoxmes() <= valorHoras) {
        menor = this->getmontoxmes();
    } else if (valorGigas <= valorHoras && valorHoras <= this->getmontoxmes()){
        menor = valorGigas;
    } else {
        menor = valorHoras;
    }

    return menor * 1.10;
}
