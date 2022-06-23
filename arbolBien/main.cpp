#include "arbolbinario.h"
#include "pila.h"
#include <iostream>
int main(int argc, char *argv[]){


    ArbolBinario<int> arbol;
    //Agregar esta de forma recursiva
    arbol.agregar(3);
    arbol.agregar(5);
    arbol.agregar(5);
    arbol.agregar(7);
    arbol.agregar(1);
    arbol.agregar(7);
    arbol.agregar(4);
    arbol.agregar(2);
    arbol.agregar(0);

    //Mostrar esta sobrecargado el operador << y de forma inorder iterativa
    std::cout << arbol << ".\n";
    std::cout << "DESPUES DE LIMPIAR\n";
    arbol.limpiar();
    std::cout << arbol;

    return 0;
}

