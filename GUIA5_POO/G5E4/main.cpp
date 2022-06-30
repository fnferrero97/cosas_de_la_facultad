#include <iostream>
#include "vectordinamico.h"
#include "caja.h"

using namespace std;

int main(int argc, char *argv[]){

    VectorDinamico<int> vd;

    for (int i = 1; i < 11; i++){
        vd.agregarElemento(i);
    }

    vd.quitarElemento(4);
    vd.quitarElemento(9);

    cout << vd.getCantElementos() << endl;
    cout << vd.getPromedio() << endl;
    cout << vd.mayorElemento() << endl;
    cout << vd.menorElemento() << endl;

    vd.mostrarDatos();
    cout << endl;

    caja caja;

    caja.calcularVueltoOptimo(1420);
    caja.mostrarVuelto();

    cout << endl;

    return 0;
}
