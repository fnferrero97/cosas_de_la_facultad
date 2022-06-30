#include <iostream>
#include "listacircular.h"
#include "mazo.h"

using namespace std;

int main(int argc, char *argv[]){

    mazo mazo;
    int cant;

    cout << "Mazo sin mezclar: \n";
    cout << "----------------------\n----------------------\n";
    cout << mazo;
    cout << "----------------------\n----------------------\n";

    do {
        cout << "Ingrese la cantidad de veces que quiere mezclar: ";
        cin >> cant;
        if (cant <= 0) {
            cout << "Numero invalido.\n";
            }
    } while (cant <= 0);

    mazo.mezclar(cant);
    cout << "Mazo despues de mezclar " << cant << " veces: \n----------------------\n";
    cout << mazo;
    cout << "----------------------\n\n";
    cout << "----------------------\n\n";
    mazo.repartir();
    cout << mazo;

    return 0;
}
