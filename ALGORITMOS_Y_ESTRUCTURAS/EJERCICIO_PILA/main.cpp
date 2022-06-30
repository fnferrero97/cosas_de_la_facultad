#include <iostream>
#include <time.h>

using namespace std;

struct nodo_pila {
    int dato;
    nodo_pila* link;
};
typedef struct nodo_pila NPila;

void alta_pila(nodo_pila* &pila, int nuevo_dato);
int obtener_pila(nodo_pila* &pila);
bool pila_vacia(nodo_pila* pila);
void ejercicio(nodo_pila* &pila);

int main(int argc, char *argv[]){

    srand(time(NULL));

    NPila* pila = NULL;

    ejercicio(pila);

    return 0;
}

void alta_pila(NPila* &pila, int nuevo_dato){

    NPila* nuevo_nodo = new(NPila);
    nuevo_nodo -> dato = nuevo_dato;
    nuevo_nodo -> link = pila;
    pila = nuevo_nodo;

}

int obtener_pila(NPila* &pila){

    int dato = pila -> dato;
    NPila* aux = pila;
    pila = aux->link;
    delete aux;

    return dato;
}

bool pila_vacia(NPila* pila){
    return pila == NULL;
}

void ejercicio(NPila* &pila){

    for (int i = 0; i < 5; i++){
        int valor = rand()&101-1;
        cout << "Ingresando el valor: " << valor << " a la pila." << endl;
        alta_pila(pila, valor);
    }

    cout << "-----------" << endl;

    while(!pila_vacia(pila)){
        cout << "Sacando el valor: " << obtener_pila(pila) << " de la pila." << endl;
    }

    cout << "-----------" << endl;

}
