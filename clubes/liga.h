#ifndef LIGA_H
#define LIGA_H
#include "equipo.h"
//#include "vector.h"
#include "fecha.h"
#include <vector>


class Liga{
private:
    std::vector<Equipo> equipos;
    std::vector<Fecha> fechas;
    int cantEquipos = 0;
    int cantFechas;
    int cantPartidos;
    void agregarFecha(Fecha);
    int getCantEquipos() const;
public:
    Liga();
    void agregarEquipo(Equipo);
    void generarFechas();
    void mostrarEquipos();
    void mostrarFechas();

};

#endif // LIGA_H
