#include "arbolbinario.h"
#include "pila.h"
#include "cola.h"
#include <iostream>
int main(int argc, char *argv[]){

    ArbolBinario<int> arbol;
    //Agregar esta de forma recursiva
    arbol.agregar(30);
    arbol.agregar(18);
    arbol.agregar(45);
    arbol.agregar(10);
    arbol.agregar(42);
    arbol.agregar(67);

    std::cout << arbol << ".\n";
    std::cout << "Altura: " << arbol.calcularAltura() << "\n";
    std::cout << "Nodos: " << arbol.calcularNodos() << "\n";
    std::cout << "MAX: " << arbol.getMaximo() << "\n";
    std::cout << "MIN: " << arbol.getMinimo() << "\n";
    std::cout << arbol.calcularHojas() << " hojas. \n";
    std::cout << "---------------------------\n";

    arbol.eliminarValor(5);

    std::cout << arbol << ".\n";
    std::cout << "Altura: " << arbol.calcularAltura() << "\n";
    std::cout << "Nodos: " << arbol.calcularNodos() << "\n";
    std::cout << "MAX: " << arbol.getMaximo() << "\n";
    std::cout << "MIN: " << arbol.getMinimo() << "\n";
    std::cout << arbol.calcularHojas() << " hojas. \n";
    std::cout << "---------------------------\n";


//    std::cout << "DESPUES DE LIMPIAR\n";
//    arbol.limpiar();
//    std::cout << arbol;

    return 0;
}

