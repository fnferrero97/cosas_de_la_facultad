#include <iostream>
#include <time.h>

using namespace std;

struct nodo_listase{
    int dato;
    nodo_listase* link;
};
typedef struct nodo_listase NListase;

void mostrarLista(NListase* lista);
void agregarAlFinal(NListase* &lista, int ndato);
void agregarOrdenada(NListase* &lista, int ndato);

int main(int argc, char *argv[]){

    srand(time(NULL));
    NListase* lista = NULL;

    for(int i = 0; i <= 40; i+=10){
        agregarAlFinal(lista, i+10);
    }

    mostrarLista(lista);

    agregarOrdenada(lista,15);
    agregarOrdenada(lista,5);
    agregarOrdenada(lista,5);
    agregarOrdenada(lista,25);
    agregarOrdenada(lista,60);

    mostrarLista(lista);

    delete lista;
    return 0;
}

void mostrarLista(NListase* lista){

    while(lista != NULL){
       cout << lista->dato << "  ";
       lista = lista->link;
    }
    cout << endl << endl;

}

void agregarOrdenada(NListase* &lista, int ndato){

    NListase* actual = lista;
    NListase* anterior = NULL;
    NListase* nuevo_nodo = new(NListase);

    nuevo_nodo -> dato = ndato;

    while(actual != NULL && actual->dato < ndato){
        anterior = actual;
        actual = actual->link;
    }

    if(anterior == NULL){
        nuevo_nodo -> link = lista;
        lista = nuevo_nodo;
    } else {
       nuevo_nodo -> link = anterior->link;
       anterior -> link = nuevo_nodo;
    }

}

void agregarAlFinal(NListase* &lista, int ndato){

    NListase* aux = lista;
    NListase* nuevo_nodo = new(NListase);

    nuevo_nodo -> dato = ndato;
    nuevo_nodo -> link = NULL;

    if(lista != NULL){
        while(aux->link != NULL){
            aux = aux->link;
        }
       aux->link = nuevo_nodo;
    } else {
        lista = nuevo_nodo;
    }
}

