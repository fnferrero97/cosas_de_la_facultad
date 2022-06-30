#include <iostream>

using namespace std;

const float IVA = 1.13;
const float DESC = 0.05;

int main(int argc, char *argv[])
{
    float precio, importe;

    cout << "Ingrese el precio: ";
    cin >> precio;

    if (precio > 50){
        importe = (precio - precio * DESC) * IVA;
    } else {
        importe = precio * IVA;
    }

    cout << "El importe es de: " << importe << endl;


    return 0;
}
