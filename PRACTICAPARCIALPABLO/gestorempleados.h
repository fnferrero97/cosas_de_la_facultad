#ifndef GESTOREMPLEADOS_H
#define GESTOREMPLEADOS_H
#include "empleado.h"

class gestorEmpleados{
private:
    Empleado* empleados[10];
    int cont = 0;
public:
    gestorEmpleados();
    void agregarEmpleado(Empleado*);
    void listarEmpleados();
};

#endif // GESTOREMPLEADOS_H
