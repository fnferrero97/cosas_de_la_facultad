#include <iostream>
#include <ArbolB/ArbolB.h>
#include <ArbolAVL/ArbolAVL.h>
#include <ColaDinamica/ColaDinamica.h>
#include <PilaDinamica/PilaDinamica.h>


int main(int argc, char *argv[]){

    ArbolB<int> ab(2);
    ArbolAVL<int> avl;
    ArbolBinarioBusqueda<int> abb;
    PilaDinamica<int> pD;
    ColaDinamica<int> cL;

    abb.agregar(5);
    abb.agregar(5);
    abb.agregar(20);
    abb.agregar(10);
    abb.agregar(4);
    abb.agregar(25);
    abb.agregar(21);
    abb.agregar(30);

    std::cout << abb << "\n";

    std::cout << "-----------------------------------\n";
    std::cout << "-----------------------------------\n";

    avl.agregar(10);
    avl.agregar(20);
    avl.agregar(5);
    avl.agregar(4);
    avl.agregar(25);
    avl.agregar(21);
    avl.agregar(30);

    std::cout << avl << "\n";

    return 0;
}

