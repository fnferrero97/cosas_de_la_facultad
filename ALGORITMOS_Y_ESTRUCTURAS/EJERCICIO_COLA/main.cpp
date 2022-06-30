#include <iostream>
#include <time.h>

using namespace std;

struct nodo_cola{

    int dato;
    nodo_cola* link;
};
typedef struct nodo_cola NCola;

void alta_cola(NCola* &frente, NCola* &fondo, int nuevo_dato);
int obtener_cola(NCola* &frente, NCola* &fondo);
bool cola_vacia(NCola* frente, NCola* fondo);
void ejercicio(NCola* frente, NCola* fondo);


int main(int argc, char *argv[])
{

    srand(time(NULL));

    NCola* frente = NULL;
    NCola* fondo = NULL;

    ejercicio(frente, fondo);

    return 0;

    return 0;
}


void alta_cola(NCola* &frente, NCola* &fondo, int nuevo_dato){

    NCola* nueva_cola = new(NCola);
    nueva_cola -> dato = nuevo_dato;
    nueva_cola -> link = NULL;

    if (frente == NULL){
        frente = nueva_cola;
    } else {
        fondo -> link = nueva_cola;
    }

    fondo = nueva_cola;

}

int obtener_cola(NCola* &frente, NCola* &fondo){

    int dato = frente -> dato;
    NCola* aux = frente;

    if (frente == fondo){
        frente = NULL;
        fondo = NULL;
    } else {
        frente = frente -> link;
    }

    delete aux;

    return dato;
}

bool cola_vacia(NCola* frente, NCola* fondo){
    return (frente == NULL && fondo == NULL);
}

void ejercicio(NCola* frente, NCola* fondo){

    for (int i = 0; i < 5; i++){
        int valor = rand()&101-1;
        cout << "Ingresando el valor: " << valor << " a la cola." << endl;
        alta_cola(frente, fondo, valor);
    }

    cout << "-----------" << endl;

    while(!cola_vacia(frente, fondo)){
        cout << "Sacando el valor: " << obtener_cola(frente, fondo) << " de la cola." << endl;
    }

    cout << "-----------" << endl;

}
