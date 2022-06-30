#include <iostream>

using namespace std;

int recursiva(int x);

    int main(int argc, char *argv[]) {

        int numero;

        cout << "Ingrese un numero: ";

        cin >> numero;

        cout << "El resultado es: " << recursiva(numero) << endl;

        return 0;
}

int recursiva(int x){

    if(x < 4){
        return 4 * x;
    } else {
        return 3 * recursiva(x - 2) + 1;
    }
}
