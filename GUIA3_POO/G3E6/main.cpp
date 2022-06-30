#include <iostream>

using namespace std;

int* remuevePrimerEncontrado(int* arreglo, int cont, int dato);
int cuentaIguales(int arreglo[], int cont, int dato);
void muestraArreglo(int arreglo[], int cont);


int main(int argc, char *argv[])
{
    int* arregloDinamico = new int[5];
    arregloDinamico[0] = 1;
    arregloDinamico[1] = 2;
    arregloDinamico[2] = 2;
    arregloDinamico[3] = 3;
    arregloDinamico[4] = 5;

    muestraArreglo(arregloDinamico, 5);

    int* arregloMas = remuevePrimerEncontrado(arregloDinamico, 5, 2);

    muestraArreglo(arregloMas, 3);


    return 0;
}

int* remuevePrimerEncontrado(int* arreglo, int cont, int dato){

    int* aux = new int[cont-cuentaIguales(arreglo, cont, dato)];
    int j = 0;

    for (int i = 0; i < cont; i++){
        if (arreglo[i] != dato){
            aux[j] = arreglo[i];
            j++;
        }
    }

    delete[] arreglo;
    return aux;
}

int cuentaIguales(int arreglo[], int cont, int dato){

    int total = 0;

    for (int i = 0; i < cont; i++){
        if (dato == arreglo[i]){
            total++;
        }
    }

    return total;

}

void muestraArreglo(int arreglo[], int cont){

   for (int i = 0; i < cont; i++){
       cout << arreglo[i] << " ";
   }

   cout << endl;

}
