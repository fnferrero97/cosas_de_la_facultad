#include "partido.h"
#include <iomanip>




Partido::Partido(){}

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

void Partido::setLocal(const Equipo& local){
    this->local = local;
}

void Partido::setVisitante(const Equipo& visitante){
    this->visitante = visitante;
}

void Partido::setEquipos(const Equipo& equipo1, const Equipo& equipo2){
    this->local = equipo1;
    this->visitante = equipo2;
}
