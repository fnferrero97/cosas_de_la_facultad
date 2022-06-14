#include "arbolbinario.h"
#include <iostream>

int main(int argc, char *argv[]){

    ArbolBinario<float> arbol;
    arbol.agregar(3.5);
    arbol.agregar(5);
    arbol.agregar(5.5);
    arbol.agregar(7.5);
    arbol.agregar(1.1);
    arbol.agregar(7.5);
    arbol.agregar(4.0);
    arbol.agregar(2.005);
    arbol.agregar(0.125);

    std::cout << arbol << ".\n";
    std::cout << "DESPUES DE LIMPIAR\n";
    arbol.limpiar();
    std::cout << arbol;

    return 0;
}

