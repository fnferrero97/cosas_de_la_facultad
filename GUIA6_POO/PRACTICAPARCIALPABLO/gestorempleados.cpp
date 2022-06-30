#include "gestorempleados.h"


gestorEmpleados::gestorEmpleados(){}

void gestorEmpleados::agregarEmpleado(Empleado* empleado){
    this->empleados[this->cont++] = empleado;
}

void gestorEmpleados::listarEmpleados(){
    if(this->cont == 0){
        std::cout << "Lista de empleados vacia.\n";
    } else {
        for(int i = 0; i < this->cont ; i++){
            this->empleados[i]->getInfo();
            std::cout << "\n";
        }
    }
}
