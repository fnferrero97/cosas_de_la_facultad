#include <iostream>

using namespace std;

int* removerPosicionParametro(int* arreglo, int cont, int pos);
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

    int* arregloMas = removerPosicionParametro(arregloDinamico, 5, 2);

    muestraArreglo(arregloMas,4);


    return 0;
}

int* removerPosicionParametro(int* arreglo, int cont, int pos){

    if (pos > cont){
        return arreglo;
    } else {
        int* aux = new int[cont-1];
        int j = 0;

        for (int i = 0; i < cont; i++){
            if(i != pos-1){
                aux[j] = arreglo[i];
                j++;
            }
        }

        delete[] arreglo;
        return aux;
    }
}


void muestraArreglo(int arreglo[], int cont){

   for (int i = 0; i < cont; i++){
       cout << arreglo[i] << " ";
   }

   cout << endl;

}
