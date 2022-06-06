#ifndef PARTIDO_H
#define PARTIDO_H
#include "equipo.h"
#include "vector.h"
#include <iostream>

class Partido{
    Equipo local;
    Equipo visitante;
public:
    Partido(Equipo, Equipo);
    void mostrarInfo();
    Equipo& getLocal();
    Equipo& getVisitante();
};

#endif // PARTIDO_H
