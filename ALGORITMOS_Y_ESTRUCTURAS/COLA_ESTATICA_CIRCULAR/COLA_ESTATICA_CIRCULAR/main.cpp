#include <iostream>
#include "colacircular.h"

using namespace std;

int main(int argc, char *argv[]){

    ColaCircular<int> cola;

    cola.agregar(10);
    cola.agregar(20);
    cola.obtener();
    cola.agregar(30);
    cola.agregar(40);
    cola.agregar(50);
    cola.obtener();
    cola.obtener();
    cola.obtener();



    return 0;
}

