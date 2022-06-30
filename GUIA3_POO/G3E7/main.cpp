#include <iostream>

using namespace std;

int* eliminaCantidadParametro(int* arreglo, int cont, int cantidad);
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

    int* arregloMas = eliminaCantidadParametro(arregloDinamico, 5, 2);

    muestraArreglo(arregloMas, 3);


    return 0;
}

int* eliminaCantidadParametro(int* arreglo, int cont, int cantidad){
    int* aux;

    if(cantidad < cont){
        aux = new int[cont-cantidad];

        for (int i = 0; i < cont-cantidad; i++){
            aux[i] = arreglo[i];
        }

        delete[] arreglo;

    } else {
        aux = NULL;
    }

    return aux;
}

void muestraArreglo(int arreglo[], int cont){

   for (int i = 0; i < cont; i++){
       cout << arreglo[i] << " ";
   }

   cout << endl;

}
