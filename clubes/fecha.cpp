#include "fecha.h"


Fecha::Fecha(int nroFecha){
    this->nroFecha = nroFecha;
}

int Fecha::getNroFecha() const{
    return nroFecha;
}

void Fecha::agregarPartido(Partido partido){
    this->partidos.push_back(partido);
}

void Fecha::mostrarFecha(){
    for (size_t i = 0; i < this->partidos.size(); i++){
        this->partidos[i].mostrarInfo();
    }
}

