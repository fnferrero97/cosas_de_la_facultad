#ifndef EMPNORMAL_H
#define EMPNORMAL_H
#include "empleado.h"


class EmpNormal : public Empleado{
public:
    EmpNormal(std::string, std::string, long, float);
    float calcularSueldo();
    void getInfo();
};

#endif // EMPNORMAL_H
