#include <iostream>

using namespace std;

int** creaMatriz(int* arreglo, int cont);
int* remueveDuplicados(int* arreglo, int cont, int total);
int cantidadUnicaElementos(int* arreglo, int cont);
int cantidadUnElemento(int* arreglo, int cont, int dato);
void ordenaArreglo(int* arreglo, int cont);
void muestraMatriz(int** matriz, int cont);

int main(int argc, char *argv[]){

    int cantElementos, dato;

    do {
    cout << "Ingrese la cantidad de elementos: ";
    cin >> cantElementos;
    cout << endl;
    } while(cantElementos == 0);

    int* arreglo = new int[cantElementos];

    for(int i = 0; i < cantElementos; i++){
        cout << "Ingrese el elemento " << i+1 << ": ";
        cin >> dato;
        arreglo[i] = dato;
    }

    cout << endl << endl;;

    ordenaArreglo(arreglo, cantElementos);

    int** matriz = creaMatriz(arreglo, cantElementos);
    muestraMatriz(matriz, cantidadUnicaElementos(arreglo, cantElementos));

    delete[] arreglo;
    delete[] matriz;

    return 0;
}

int** creaMatriz(int* arreglo, int cont){

    int total = cantidadUnicaElementos(arreglo, cont);
    int* auxDos = remueveDuplicados(arreglo, cont, total);

    int** aux = new int*[total];
    for (int i = 0; i < total; i++){
        aux[i] = new int[2];
    }

    for (int i = 0; i < total; i++){
            aux[i][0] = auxDos[i];
            aux[i][1] = cantidadUnElemento(arreglo, cont, auxDos[i]);
        }

    delete[] auxDos;
    return aux;

}

int* remueveDuplicados(int* arreglo, int cont, int total){

    int* aux = new int[total];
    int j = 0;

    for (int i = 0; i < cont-1; i++){

        if (arreglo[i] != arreglo[i+1]){
            aux[j] = arreglo[i];
            j++;
        }
    }

    aux[j] = arreglo[cont-1];

    return aux;
}

int cantidadUnElemento(int* arreglo, int cont, int dato){

    int contador = 0;

    for(int i = 0; i < cont; i++){
        if(arreglo[i] == dato){
            contador++;
        }
    }

    return contador;

}

int cantidadUnicaElementos(int* arreglo, int cont){
    int contador = 1;

        for (int i = 1; i < cont; i++) {
            if (arreglo[i] != arreglo[i-1]){
                contador++;
            }
        }
        return contador;
}

void ordenaArreglo(int* arreglo, int cont){

    for(int i = 0; i < cont-1; i++){
        for(int j = i+1; j < cont; j++){
            if(arreglo[i] > arreglo[j]){
                int aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }

}

void muestraMatriz(int** matriz, int cont){

    cout << "-------------------" << endl;
    cout << "Numero  -  Cantidad" << endl << endl;
    for (int i = 0; i < cont; i++){
        for (int j = 0; j < 2; j++){
        cout << "   " << matriz[i][j] << "       ";
    }
    cout << endl;
    }
    cout << endl << "-------------------" << endl << endl;
}
