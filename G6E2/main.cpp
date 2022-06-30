#include <iostream>
#include <string>
#include "vector.h"
#include "gestorgastos.h"
#include "gastocompra.h"
#include "gastoservicio.h"
#include "gastoextraordinario.h"

void mostrarMenu(){
    std::cout << "==== Menu ====" << std::endl;
    std::cout << "Opcion 1) Agregar gasto de Compra." << std::endl;
    std::cout << "Opcion 2) Agregar gasto de Servicio." << std::endl;
    std::cout << "Opcion 3) Agregar gasto extraordinario." << std::endl;
    std::cout << "Opcion 4) Listar gastos." << std::endl;
    std::cout << "Opcion 5) Listar total de gastos." << std::endl;
    std::cout << "Opcion 6) Salir." << std::endl;
    std::cout << "==============" << std::endl;
    std::cout << std::endl;
    std::cout << "Ingrese la opcion: ";
}

int main(int argc, char *argv[]){

    gestorGastos gestor;
    int opcion;
    float valor;
    std::string detalle;

    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cout << std::endl;
        std::cin.ignore();

        switch(opcion){
        case 1: {

            std::cout << "Ingrese el nombre del producto: ";
            std::getline(std::cin, detalle);
            std::cout << "Ingrese el precio del producto: ";
            std::cin >> valor;
            std::cout << std::endl;
            gasto* gasto = new gastoCompra(detalle, valor);
            gestor.agregarGasto(gasto);
            break;
        }
        case 2: {
            std::cout << "Ingrese el nombre de la empresa: ";
            std::getline(std::cin, detalle);
            std::cout << "Ingrese el precio del servicio: ";
            std::cin >> valor;
            std::cout << std::endl;
            gasto* gasto = new gastoServicio(detalle, valor);
            gestor.agregarGasto(gasto);
            break;
        }
        case 3: {
            std::cout << "Ingrese descripcion del gasto: ";
            std::getline(std::cin, detalle);
            std::cout << "Ingrese el precio del gasto: ";
            std::cin >> valor;
            std::cout << std::endl;
            gasto* gasto = new gastoExtraordinario(detalle, valor);
            gestor.agregarGasto(gasto);
            break;
        }
        case 4: {
            gestor.listarGastos();
            std::cout << std::endl;
            break;
            }
        case 5: {
            gestor.calculaTotales();
            break;
            }
        case 6: {
            std::cout << "Gracias por utilizar el programa" << std::endl;
            break;
            }
        default: {
            std::cout << "Opcion no valida." << std::endl << std::endl;
            break;
            }
        }

    }while(opcion != 6);


    return 0;
}
