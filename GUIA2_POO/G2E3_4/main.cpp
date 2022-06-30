#include <iostream>

using namespace std;

int mayorRecursivo(int arr[], int cont, int indice);
int menorRecursivo(int arr[], int cont, int indice);

int main(int argc, char *argv[])
{
    int array[] = {-4, 1, 5, 2, 3};
    int tamanio = (sizeof(array) / sizeof(int));

    cout << "El mayor elemento es: " << mayorRecursivo(array, tamanio-1, 0);

    cout << endl;

    cout << "El menor elemento es: " << menorRecursivo(array, tamanio-1, 0);

    cout << endl;
    return 0;
}


int mayorRecursivo(int arr[], int cont, int indice){

    if (indice == cont){
        return arr[indice];
    } else if (arr[indice] > mayorRecursivo(arr, cont, indice+1)){
        return arr[indice];
    } else {
        return mayorRecursivo(arr, cont, indice+1);
    }
}

int menorRecursivo(int arr[], int cont, int indice){

    if (indice == cont){
        return arr[indice];
    } else if (arr[indice] < menorRecursivo(arr, cont, indice+1)){
        return arr[indice];
    } else {
        return menorRecursivo(arr, cont, indice+1);
    }
}
