#include "empnormal.h"
#include "empencargado.h"
#include "empvendedor.h"
#include "empleado.h"
#include "gestorempleados.h"
#include <iostream>


int main(int argc, char *argv[]){

    Empleado* e1 = new EmpNormal("Pablo", "Beckmann", 123456789, 15000);
    Empleado* e2 = new EmpVendedor("Facundo", "Ferrero", 987654321, 20000, 100);
    Empleado* e3 = new EmpEncargado("Tomi", "God",989898989, 30000, 3);
    Empleado* e4 = new EmpNormal("Joaco", "Martinez", 40166618,18000);

    gestorEmpleados gestor;
    gestor.agregarEmpleado(e1);
    gestor.agregarEmpleado(e2);
    gestor.agregarEmpleado(e3);
    gestor.agregarEmpleado(e4);

    gestor.listarEmpleados();

    return 0;
}
