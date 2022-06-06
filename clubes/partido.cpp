#include "partido.h"


Partido::Partido(Equipo local, Equipo visitante){
    this->local = local;
    this->visitante = visitante;
}

void Partido::mostrarInfo(){
    std::cout << this->getLocal().getNombre() << " vs. " << this->getVisitante().getNombre() << "\n";
}

Equipo& Partido::getLocal(){
    return local;
}
Equipo& Partido::getVisitante(){
    return visitante;
}
