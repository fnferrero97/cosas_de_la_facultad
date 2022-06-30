#include <iostream>

using namespace std;

int* remuevePrimerEncontrado(int* arreglo, int cont, int dato);
int buscaPosicion(int arreglo[], int cont, int dato);
void muestraArreglo(int arreglo[], int cont);


int main(int argc, char *argv[])
{
    int* arregloDinamico = new int[5];
    arregloDinamico[0] = 1;
    arregloDinamico[1] = 4;
    arregloDinamico[2] = 4;
    arregloDinamico[3] = 4;
    arregloDinamico[4] = 5;

    muestraArreglo(arregloDinamico, 5);

    int* arregloMas = remuevePrimerEncontrado(arregloDinamico, 5, 4);

    muestraArreglo(arregloMas, 4);


    return 0;
}

int* remuevePrimerEncontrado(int* arreglo, int cont, int dato){

    int* aux = new int[cont-1];
    int j = 0;
    int pos = buscaPosicion(arreglo, cont, dato);

    for (int i = 0; i < cont; i++){
        if (i != pos){
            aux[j] = arreglo[i];
            j++;
        }
    }

    delete[] arreglo;
    return aux;
}

int buscaPosicion(int arreglo[], int cont, int dato){

    for (int i = 0; i < cont; i++){
        if (dato == arreglo[i]){
            return i;
        }
    }

    return -1;

}

void muestraArreglo(int arreglo[], int cont){

   for (int i = 0; i < cont; i++){
       cout << arreglo[i] << " ";
   }

   cout << endl;

}
