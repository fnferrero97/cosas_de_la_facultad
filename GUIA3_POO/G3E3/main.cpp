#include <iostream>

using namespace std;

int* agregaParametroPosicion(int* arreglo, int cont, int nuevo_dato, int pos);
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

    int* arregloMas = agregaParametroPosicion(arregloDinamico, 5, 6, 3);

    muestraArreglo(arregloMas,6);


    return 0;
}

int* agregaParametroPosicion(int* arreglo, int cont, int nuevo_dato, int pos){

    int* aux = new int[cont+1];
    int j = 0;

    for(int i = 0; i < cont+1; i++){
        if(i == pos-1){
            aux[i] = nuevo_dato;
        } else {
            aux[i] = arreglo[j];
            j++;
        }
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
