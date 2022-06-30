#include <iostream>
#include <string>

using namespace std;

class vectorDinamico{

public:
    vectorDinamico(){
    }

    int* Union(int* arreglo1, int t1, int* arreglo2, int t2){

        int nuevoTamanio = t1 + t2;
        int* arregloUnido = new int[nuevoTamanio];

        for (int i = 0; i < nuevoTamanio; i++){
                if (i < t1) {
                    arregloUnido[i] = arreglo1[i];
                }
                else {
                    arregloUnido[i] = arreglo2[i - t1];
                }
            }
        return arregloUnido;
    }

    int* Interseccion(int* arreglo1, int t1, int* arreglo2, int t2){

        int* arregloIntersecado = new int[this->cuentaIguales(arreglo1, t1, arreglo2, t2)];
        int k = 0;

        for (int i = 0; i < t1; i++){
            for(int j = 0; j < t2; j++){
                if(arreglo1[i] == arreglo2[j]){
                arregloIntersecado[k] = arreglo1[i];
                k++;
                }
            }
        }

        return arregloIntersecado;
    }

    int cuentaIguales(int* arreglo1, int t1, int* arreglo2, int t2){
        int contador = 0;

        for (int i = 0; i < t1; i++){
            for(int j = 0; j < t2; j++)
                if(arreglo1[i] == arreglo2[j])
                contador++;
        }

        return contador;
    }

    void Mostrar(int* arreglo, int t){
        for(int i = 0; i < t; i++){
            cout << arreglo[i] << " - ";
        }
    }

};

int main(int argc, char *argv[]){

    int arr1[] = {10, 25, 35, 55};
    int arr2[] = {10, 25, 90, 105, 25, 45};

    vectorDinamico* vD = new vectorDinamico();

    vD->Mostrar(vD->Union(arr1, 4, arr2, 6), 10);

    cout << endl;

    vD->Mostrar(vD->Interseccion(arr1, 4, arr2, 6), vD->cuentaIguales(arr1, 4, arr2, 6));

    cout << endl;

    delete vD;
    return 0;
}
