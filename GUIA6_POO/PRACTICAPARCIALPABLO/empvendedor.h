#ifndef EMPVENDEDOR_H
#define EMPVENDEDOR_H
#include "empleado.h"


class EmpVendedor : public Empleado{
private:
    float montoVendido;
public:
    EmpVendedor(std::string, std::string, long, float, float);
    float calcularSueldo();
    void getInfo();
    float getMontoVendido() const;
    void setMontoVendido(float);
};
#endif // EMPVENDEDOR_H
