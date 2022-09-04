#include <iostream>
#include "gestorclientes.h"
#include "cliente.h"
#include "factura.h"
#include "facturatiempo.h"
#include "facturamixta.h"
#include "facturagiga.h"

int main(){
    float montoxmes, montoxtiempo, montoxgiga, deuda;
    int nroCliente, opcion, cantHoras, cantGigas, respuesta;
    GestorClientes gestor;

    std::cout << "Ingrese monto fijo por mes: ";
    std::cin >> montoxmes;
    std::cout << "Ingrese monto fijo por tiempo: ";
    std::cin >> montoxtiempo;
    std::cout << "Ingrese monto fijo por giga: ";
    std::cin >> montoxgiga;
    std::cout << "Ingrese valor de deuda: ";
    std::cin >> deuda;

    std::cout << "\n\nCARGA DE CLIENTES\n\n";

    do {
        std::cout << "Ingrese numero de cliente: ";
        std::cin >> nroCliente;

        std::cout << "\n0: FACTURA TIEMPO -- 1: FACTURA GIGA -- 2: FACTURA MIXTA\n"
                     "Ingrese tipo de factura: ";

        std::cin >> opcion;

        switch(opcion){
                case 0:{
                    std::cout << "Ingrese cantidad horas: ";
                    std::cin >> cantHoras;
                    Factura* factura = new FacturaTIEMPO(montoxmes, montoxtiempo, montoxgiga, cantHoras);
                    Cliente cliente(nroCliente, factura);
                    gestor.agregarCliente(cliente);
                }
                break;

                case 1:{
                    std::cout << "Ingrese cantidad gigas: ";
                    std::cin >> cantGigas;
                    Factura* factura = new FacturaGIGA(montoxmes, montoxtiempo, montoxgiga, cantHoras);
                    Cliente cliente(nroCliente, factura);
                    gestor.agregarCliente(cliente);
                    }
                break;

                case 2:{
                    std::cout << "Ingrese cantidad horas: ";
                    std::cin >> cantHoras;
                    std::cout << "Ingrese cantidad gigas: ";
                    std::cin >> cantGigas;
                    Factura* factura = new FacturaMIXTA(montoxmes, montoxtiempo, montoxgiga, cantHoras, cantGigas);
                    Cliente cliente(nroCliente, factura);
                    gestor.agregarCliente(cliente);
                    }
                    break;
        };

        std::cout << "Desea agregar otro cliente? (0 SI - 1 NO): ";
        std::cin >> respuesta;

    } while (respuesta != 1);

    gestor.generarCobros();
    std::cout << "TOTAL A COBRAR: " << gestor.getacumCobrar() << "\n";
    std::cout << "CLIENTES CON VALOR DE DEUDAS MAYOR A " << deuda << "\n";
    gestor.listarClientesDeudas(deuda);

    return 0;
}
