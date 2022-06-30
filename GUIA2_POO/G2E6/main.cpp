#include <iostream>

using namespace std;

void intercambio(int arr[], int com, int final);

int main(int argc, char *argv[])
{
    int array[] = {1, 2, 3, 4, 5};
    int tamanio = (sizeof(array) / sizeof(int));

    cout << endl << "ANTES DEL INTERCAMBIO" << endl;

    for (int i = 0; i < tamanio; i++){
        cout << array[i] << " ";
    }

    cout << endl << "INTERCAMBIO RECURSIVO" << endl;

    intercambio(array, 0, tamanio-1);

    for (int i = 0; i < tamanio; i++){
        cout << array[i] << " ";
    }

    cout << endl;
    return 0;
}


void intercambio(int arr[], int com, int final){

    if(com <= final){
        int aux = arr[com];
        arr[com] = arr[final];
        arr[final] = aux;
        return intercambio(arr, com+1, final-1);
    }

}
