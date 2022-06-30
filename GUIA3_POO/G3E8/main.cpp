#include <iostream>

using namespace std;

int* duplicaArreglo(int* arreglo, int cont);
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

    int* arregloMas = duplicaArreglo(arregloDinamico, 5);

    muestraArreglo(arregloMas,10);


    return 0;
}

int* duplicaArreglo(int* arreglo, int cont){

        int* aux = new int[cont*2];

        for (int i = 0; i < cont; i++){
            aux[i] = arreglo[i];
            aux[i+cont] = arreglo[i];
        }

        delete[] arreglo;
        return aux;
}

void muestraArreglo(int arreglo[], int cont){

   for (int i = 0; i < cont; i++){
       cout << arreglo[i] << " ";
   }

   cout << endl;

}
