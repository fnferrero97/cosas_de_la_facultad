#include <iostream>
#include <math.h>

using namespace std;

int division_entera(int a, int b, int &resto);
int facto(int n);
void intercambio(char &a, char &b);
float hipot(float c1, float c2);

int main(int argc, char* argv[]){

    int resto;
    char a = 'a', b = 'b';

    cout << "La hipotenusa es de: " << hipot(24, 8) << endl << endl;
    cout << "El cociente entero entre 11 y 5 es " << division_entera(11,5,resto) << " y el resto es de " << resto << endl << endl;
    cout << "El factorial de 3 es " << facto(3) << endl << endl;

    cout << "La variable a antes del cambio tiene por valor: " << a << endl;
    cout << "La variable b antes del cambio tiene por valor: " << b << endl << endl;
    intercambio(a,b);
    cout << "La variable a luego del cambio tiene por valor: " << a << endl;
    cout << "La variable b luego del cambio tiene por valor: " << b << endl << endl;


    return 0;
}

float hipot(float c1, float c2){
    return sqrt(pow(c1,2) + pow(c2, 2));
}

int division_entera(int a, int b, int &resto){
    resto = a & b;
    return a / b;
}

int facto(int n){
    int valor = n;
    for (int i = n-1; i > 0; i--){
        valor *= i;
    }
    return valor;
}

void intercambio(char &a, char &b){
    char aux = a;
    a = b;
    b = aux;
}
