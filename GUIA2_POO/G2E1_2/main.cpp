#include <iostream>

using namespace std;

int acumuladorRecursivo(int arr[], int cont, int indice = 0);
int promedio(int arr[], int cont);

int main(int argc, char *argv[])
{
    int array[] = {1, 2, 3, 4, 5};
    int tamanio = (sizeof(array) / sizeof(int));

    cout << "La cantidad acumulada en el arreglo es de: " << acumuladorRecursivo(array, tamanio-1) << endl;

    cout << "El promedio del arreglo es de: " << promedio(array, tamanio-1) << endl;

    return 0;
}

int acumuladorRecursivo(int arr[], int cont, int indice){

    if (indice >= cont){
        return arr[indice];
    } else {
        return arr[indice] + acumuladorRecursivo(arr, cont, indice + 1);
    }

}

int promedio(int arr[], int cont){
    return acumuladorRecursivo(arr, cont) / cont;
}
