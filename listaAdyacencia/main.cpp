#include <iostream>

struct nodoGrafo{
    int idNodo;
    struct nodoArco* listaArcos;
    struct nodoGrafo* link;

    nodoGrafo(int idNodo){
        this->idNodo = idNodo;
        this->link = nullptr;
        this->listaArcos = nullptr;
    }
};

struct nodoArco{
    int idArco;
    struct nodoGrafo* destino;
    struct nodoArco* link;

    nodoArco(int idArco, nodoGrafo* destino){
        this->idArco = idArco;
        this->destino = destino;
    }
};

bool existeIDNodo(nodoGrafo*, int);
void agregarNodo(nodoGrafo*&, int);
void agregarArco(nodoGrafo*, int, int, int);
void mostrarGrafo(nodoGrafo*);
void eliminarArco(nodoGrafo*, int, int);
void eliminarNodo(nodoGrafo*&, int);

int main(){

    nodoGrafo* grafo = nullptr;

    agregarNodo(grafo, 1);
    agregarNodo(grafo, 2);
    agregarNodo(grafo, 3);
    agregarNodo(grafo, 4);
    agregarNodo(grafo, 5);

    agregarArco(grafo, 1, 1, 4);
    agregarArco(grafo, 2, 1, 3);
    agregarArco(grafo, 3, 2, 5);
    agregarArco(grafo, 4, 2, 3);
    agregarArco(grafo, 5, 2, 1);
    agregarArco(grafo, 6, 3, 4);
    agregarArco(grafo, 7, 4, 5);
    agregarArco(grafo, 8, 4, 3);
    agregarArco(grafo, 9, 4, 2);

    /*

    1 : 3 -> 4
    2 : 1 -> 3 -> 5
    3 : 4
    4 : 2 -> 3 -> 5
    5 :

    */
    mostrarGrafo(grafo);


    eliminarArco(grafo, 3, 4);

    /*

    1 : 3 -> 4
    2 : 1 -> 3 -> 5
    3 :
    4 : 2 -> 3 -> 5
    5 :

    */

    mostrarGrafo(grafo);

    agregarArco(grafo, 10, 3, 4);
    eliminarNodo(grafo, 3);
    eliminarNodo(grafo, 1);

    mostrarGrafo(grafo);
    return 0;
}


void agregarNodo(nodoGrafo* &lista, int idNodo){
    if (existeIDNodo(lista, idNodo)) return;
    nodoGrafo* nuevoNodo = new nodoGrafo(idNodo);
    nuevoNodo->link = lista;
    lista = nuevoNodo;
}

bool existeIDNodo(nodoGrafo* lista, int idNodo){
    while (lista != nullptr){
        if (lista->idNodo == idNodo) return true;
        lista = lista->link;
    }
    return false;
}

void agregarArco(nodoGrafo* lista, int idArco, int idNodoOrigen, int idNodoDestino){
    nodoGrafo* origen = lista;
    nodoGrafo* destino = lista;

    while (lista != nullptr && (origen->idNodo != idNodoOrigen || destino->idNodo != idNodoDestino)){
        if (lista->idNodo == idNodoOrigen){
            origen = lista;
        }
        if (lista->idNodo == idNodoDestino){
            destino = lista;
        }
        lista = lista->link;
    }

    if (origen == nullptr || destino == nullptr) return;

    nodoArco* nuevoArco = new nodoArco(idArco, destino);
    nuevoArco->link = origen->listaArcos;
    origen->listaArcos = nuevoArco;
}

void eliminarNodo(nodoGrafo* &lista, int idNodo){
    nodoGrafo* actual = lista;
    nodoGrafo* anterior = nullptr;
    nodoGrafo* auxAEliminar;

    while (actual != nullptr){
        nodoArco* arcoActual = actual->listaArcos;
        nodoArco* arcoAnterior = nullptr;
        while (arcoActual != nullptr){
            arcoAnterior = arcoActual;
            arcoActual = arcoActual->link;
            if (arcoAnterior->destino->idNodo == idNodo){
                eliminarArco(lista, actual->idNodo, idNodo);
            }
        }
        actual = actual->link;
    }

    actual = lista;

    while (actual != nullptr && actual->idNodo != idNodo){
        anterior = actual;
        actual = actual->link;
    }

    if (actual == nullptr) return;

    while (actual->listaArcos != nullptr){
        eliminarArco(lista, actual->idNodo, actual->listaArcos->destino->idNodo);
    }


    if (actual != nullptr && anterior == nullptr){
        auxAEliminar = actual;
        lista = actual->link;
        delete auxAEliminar;
    } else if (actual != nullptr && anterior != nullptr){
        auxAEliminar = actual;
        anterior->link = actual->link;
        delete auxAEliminar;
    }
}

void eliminarArco(nodoGrafo* lista, int idNodoOrigen, int idNodoDestino){
    while (lista != nullptr && lista->idNodo != idNodoOrigen){
        lista = lista->link;
    }

    if (lista == nullptr) return;

    nodoArco* actual = lista->listaArcos;
    nodoArco* anterior = nullptr;
    nodoArco* auxAEliminar;

    while (actual != nullptr && actual->destino->idNodo != idNodoDestino){
        anterior = actual;
        actual = actual->link;
    }

    if (actual != nullptr && anterior == nullptr){
        auxAEliminar = actual;
        lista->listaArcos = actual->link;
        delete auxAEliminar;
    } else if (actual != nullptr && anterior != nullptr){
        auxAEliminar = actual;
        anterior->link = actual->link;
        delete auxAEliminar;
    }
}

void mostrarGrafo(nodoGrafo* lista){
    std::cout << "Grafo:\n\n";

    while (lista != nullptr){
        std::cout << "Nodo " << lista->idNodo << " ||";

        nodoArco* aux = lista->listaArcos;
        if (aux == nullptr){
            std::cout << " -> NO TIENE ARCOS\n";
            lista = lista->link;
        } else {
            while (aux != nullptr){
                std::cout << " -> " << aux->destino->idNodo;
                aux = aux->link;
            }
            std::cout << "\n";
            lista = lista->link;
        }
    }
    std::cout << "\n\n";
}
