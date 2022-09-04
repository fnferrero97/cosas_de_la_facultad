#include <iostream>
#include <ArbolB/ArbolB.h>
#include <ArbolAVL/ArbolAVL.h>
#include <ColaDinamica/ColaDinamica.h>
#include <PilaDinamica/PilaDinamica.h>


int main(){

    ArbolB<int> ab(2);
    ArbolBinarioBusqueda<int>* avl = new ArbolAVL<int>;
    ArbolBinarioBusqueda<int> abb;
    PilaDinamica<int> pD;
    ColaDinamica<int> cL;

    abb.agregar(5);
    abb.agregar(20);
    abb.agregar(10);
    abb.agregar(4);
    abb.agregar(25);
    abb.agregar(21);
    abb.agregar(30);

    abb.mostrar(15);

    std::cout << "-----------------------------------\n";
    std::cout << "-----------------------------------\n";

    avl->agregar(10);
    avl->agregar(20);
    avl->agregar(5);
    avl->agregar(4);
    avl->agregar(25);
    avl->agregar(21);
    avl->agregar(30);
    avl->eliminar(10);
    avl->eliminar(5);
    avl->eliminar(21);

    avl->mostrar(10);

    return 0;
}

