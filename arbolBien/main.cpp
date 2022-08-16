#include "arbolbinario.h"
#include <iostream>
int main(int argc, char *argv[]){

    ArbolBinario<int> arbol;
//  Agregar esta de forma iterativa
    arbol.agregar(10);
    arbol.agregar(20);
    arbol.agregar(5);
    arbol.agregar(4);
    arbol.agregar(15);

    std::cout << arbol << ".\n";

    //std::cout << arbol.cantidadNodosDescendientes(5) << "\n";

    arbol.estaCompleto();

    arbol.completarArbol();
    std::cout << arbol << ".\n";
    arbol.estaCompleto();

//    std::cout << "Altura: " << arbol.calcularAltura() << "\n";
//    std::cout << "Nodos: " << arbol.calcularNodos() << "\n";
//    std::cout << "MAX: " << arbol.getMaximo() << "\n";
//    std::cout << "MIN: " << arbol.getMinimo() << "\n";
//    std::cout << arbol.calcularHojas() << " hojas. \n";
//    std::cout << "---------------------------\n";

//    arbol.eliminarValor(5);

//    std::cout << arbol << ".\n";
//    std::cout << "Altura: " << arbol.calcularAltura() << "\n";
//    std::cout << "Nodos: " << arbol.calcularNodos() << "\n";
//    std::cout << "MAX: " << arbol.getMaximo() << "\n";
//    std::cout << "MIN: " << arbol.getMinimo() << "\n";
//    std::cout << arbol.calcularHojas() << " hojas. \n";
//    std::cout << "---------------------------\n";


//    std::cout << "DESPUES DE LIMPIAR\n";
//    arbol.limpiar();
//    std::cout << arbol;

    return 0;
}

