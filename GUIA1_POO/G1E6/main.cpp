#include <iostream>

using namespace std;

void interes(int n, float i, float c);

int main(int argc, char *argv[])
{
    int n;
    float i, c;

    cout << "Ingrese el monto incial: ";
    cin >> c;

    cout << "Ingrese la tasa de interes: ";
    cin >> i;

    cout << "Ingrese la cantidad de meses: ";
    cin >> n;

    interes(n, i, c);


    return 0;
}

void interes(int n, float interes, float c){

    c *= interes;

    for (int i = 0; i < n; i++){
        cout << "Monto a reintegrar del mes " << i+1 << " es de: " << c << endl;
        c *= interes;
    }

}
