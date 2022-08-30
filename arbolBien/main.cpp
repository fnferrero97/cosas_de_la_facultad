#include "arbolavl.h"
#include <iostream>

int main(int argc, char *argv[]){

    arbolAVL<int> avl;

    avl.agregar(3);
    avl.agregar(21);
    avl.agregar(30);
    avl.agregar(11);
    avl.agregar(13);
    avl.agregar(22);
    avl.agregar(15);
    avl.agregar(8);
    avl.agregar(24);
    avl.agregar(16);
    avl.agregar(32);
    avl.agregar(25);

    std::cout << "ALTURA: " << avl.calcularAltura() << "\n";
    std::cout << "MINIMO: " << avl.getMinimo() << "\n";
    std::cout << "MAXIMO: " << avl.getMaximo() << "\n";


    avl.mostarHorizontal2D(avl.getRaiz(), 2);

    return 0;
}

