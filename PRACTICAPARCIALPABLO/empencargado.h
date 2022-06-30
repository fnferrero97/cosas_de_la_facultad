#ifndef EMPENCARGADO_H
#define EMPENCARGADO_H
#include "empleado.h"


class EmpEncargado : public Empleado{
private:
    int objetivoLogrado;
public:
    EmpEncargado(std::string, std::string, long, float, int);
    float calcularSueldo();
    void getInfo();
    int getObjetivoLogrado() const;
    void setObjetivoLogrado(int newObjetivoLogrado);
};

#endif // EMPENCARGADO_H
