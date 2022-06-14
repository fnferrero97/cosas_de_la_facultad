#ifndef PARTIDO_H
#define PARTIDO_H
#include "equipo.h"
#include "vector.h"
#include <iostream>

class Partido{
    Equipo local;
    Equipo visitante;
public:
    Partido();
    Partido(Equipo, Equipo);
    void mostrarInfo();
    Equipo& getLocal();
    Equipo& getVisitante();
    void setLocal(const Equipo&);
    void setVisitante(const Equipo&);
    void setEquipos(const Equipo&, const Equipo&);
};

#endif // PARTIDO_H
