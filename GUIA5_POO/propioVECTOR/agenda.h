#ifndef AGENDA_H
#define AGENDA_H
#include "vector.h"
#include "cumpleanio.h"

class agenda{
private:
    Vector<cumpleanio> lista;
public:
    agenda();
    void agregarCumpleanio(cumpleanio);
    void eliminarCumpleanio(std::string);
    Vector<cumpleanio> getPorDia(int);
    Vector<cumpleanio> getPorMes(int);
    void mostrarCumpleanios();
    void mostrarCumpleanios(Vector<cumpleanio>);

};

#endif // AGENDA_H
