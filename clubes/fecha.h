#ifndef FECHA_H
#define FECHA_H
#include "partido.h"
//#include "vector.h"
#include <vector>


class Fecha{
private:
    std::vector<Partido> partidos;
    int nroFecha;
public:
    Fecha(int);
    void agregarPartido(Partido partido);
    void mostrarFecha();
    int getNroFecha() const;
};

#endif // FECHA_H
