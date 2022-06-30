#include <iostream>
#include <time.h>
#include "milibreria.h"

using namespace std;

//         _________VD___________
//         |                    |
//     CONJUNTO               LISTA
//         |                    |
//         |                    |
// CONJUNTO ORDENADO       LISTA ORDENADA


// PILA - COLA

int main(int argc, char *argv[]){

    srand(time(NULL));

    conjunto conjunto;
    conjuntoordenado co;
    lista lista;
    listaordenada lo;
    pila pila;
    cola cola;

//    for (int i = 0; i < 5; i++){
//        int valor = rand() % 300;
//        cout << "Ingresando el valor: " << valor << " a la cola." << endl;
//        cola.alta_cola(valor);
//    }

//    cout << "-----------" << endl;

//    while(!cola.cola_vacia()){
//        cout << "Sacando el valor: " << cola.baja_cola() << " de la cola." << endl;
//    }

//    cout << "-----------" << endl;

    for (int i = 0; i < 5; i++){
        int valor = rand()%101-1;
        cout << "Ingresando el valor: " << valor << " a la pila." << endl;
        pila.alta_pila(valor);
    }

    cout << "-----------" << endl;

    while(!pila.pila_vacia()){
        cout << "Sacando el valor: " << pila.baja_pila() << " de la pila." << endl;
    }


//    co.agregar(1);
//    co.agregar(5);
//    co.agregar(3);
//    co.agregar(5);
//    co.agregar(0);

//    for(int i = 0; i < co.getTamanio(); i++){
//        cout << co[i] << " ";
//    }

    cout << "\n";

    return 0;
}
