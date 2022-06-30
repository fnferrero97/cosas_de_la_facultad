#include <iostream>

using namespace std;

int* agregaUltimaPosicion(int* arreglo, int cont, int nuevo_dato);
void muestraArreglo(int arreglo[], int cont);

int main(int argc, char *argv[])
{
    int* arregloDinamico = new int[5];
    arregloDinamico[0] = 1;
    arregloDinamico[1] = 2;
    arregloDinamico[2] = 3;
    arregloDinamico[3] = 4;
    arregloDinamico[4] = 5;

    muestraArreglo(arregloDinamico, 5);

    int* arregloMas = agregaUltimaPosicion(arregloDinamico, 5, 6);

    muestraArreglo(arregloMas,6);


    return 0;
}

int* agregaUltimaPosicion(int* arreglo, int cont, int nuevo_dato){

    int* aux = new int[cont+1];

    for(int i = 0; i < cont; i++){
        aux[i] = arreglo[i];
    }

    aux[cont] = nuevo_dato;
    delete[] arreglo;

    return aux;
}

void muestraArreglo(int arreglo[], int cont){

   for (int i = 0; i < cont; i++){
       cout << arreglo[i] << " ";
   }

   cout << endl;

}
