#include <iostream>

using namespace std;

void llenaArrayRecursivo(int* &array, int cont, int iterador = 0);

int main(int argc, char *argv[])
{
    int tamanio;

    cout << "Ingrese el tamanio del vector: ";
    cin >> tamanio;

    cout << endl;

    int* punteroArray = new int[tamanio];

    llenaArrayRecursivo(punteroArray, tamanio);

    cout << endl;

    for (int i = 0; i < tamanio; i++){
        cout << *(punteroArray+i) << " ";
    }

    cout << endl << "----------------" << endl;;

    delete[] punteroArray;

    return 0;
}


void llenaArrayRecursivo(int* &array, int cont, int iterador){

    int valor_ingresado;

    if(iterador < cont){
        cout << "Ingrese el nuevo valor: ";
        cin >> valor_ingresado;
        *(array+iterador) = valor_ingresado;
        llenaArrayRecursivo(array, cont, iterador+1);
    }

}
