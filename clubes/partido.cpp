#include "partido.h"
#include <iomanip>


Partido::Partido(Equipo local, Equipo visitante){
    this->local = local;
    this->visitante = visitante;
}

void Partido::mostrarInfo(){
    std::cout << std::right <<std::setw(25) << this->getLocal().getNombre() << "  -- vs. --  "
    << std::left << std::setw(25)<< this->getVisitante().getNombre() << "\n";
}

Equipo& Partido::getLocal(){
    return local;
}
Equipo& Partido::getVisitante(){
    return visitante;
}
