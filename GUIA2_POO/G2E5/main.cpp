#include <iostream>

using namespace std;

int trianguloPascal(int f, int c);

int main(int argc, char *argv[]){

    int f, c;

     cout << "Ingrese la columna: ";
     cin >> c;

     cout << "Ingrese la fila: ";
     cin >> f;

      cout << endl;

     for(int i = 1; i < 17; i++){
         for(int j = 1; j <= i; j++){
             cout << trianguloPascal(i-1,j-1) << " ";
         }
         cout << endl;
     }

     cout << endl;

     cout << "El numero en el triangulo de pascal para la fila: " << f << " y columna: " << c << " es: " << trianguloPascal(f-1,c-1) << endl;

     return 0;
}

int trianguloPascal(int f, int c){

    if (c == 0)
        return 1;

    if (f == 0 || f == c)
        return 1;

    return trianguloPascal(f - 1, c - 1) + trianguloPascal(f - 1, c);
}
