#include <iostream>
#include "empresa.h"


int main(){

    Empresa empresa;
    empresa.generarArchivo();
    empresa.cargarEmpleados();
    empresa.generarTxt();

    std::vector<Empleado> mayores = empresa.getMayores();
    std::vector<Empleado> menores = empresa.getMenores();

    std::cout << "Empleados que trabajaron mas: \n";
    for (auto emp : mayores){
        std::cout << emp.getNombre() << " " << emp.getApellido() << " HRS: " << emp.getHorasTrabajadas() << "\n";
    }

    std::cout << "Empleados que trabajaron menos: \n";
    for (auto emp : menores){
        std::cout << emp.getNombre() << " " << emp.getApellido() << " HRS: " << emp.getHorasTrabajadas() << "\n";
    }

    return 0;
}
