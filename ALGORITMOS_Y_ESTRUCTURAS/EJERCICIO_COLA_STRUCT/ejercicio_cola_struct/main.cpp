#include <iostream>
#include <string>
#include <time.h>

using namespace std;

struct Datos {
    int edad;
    string nombre;
};

struct nodo_cola{
    Datos dato;
    nodo_cola* link;
};
typedef struct nodo_cola NCola;

void alta_cola(NCola* &frente, NCola* &fondo, Datos nuevos_datos);
Datos obtener_cola(NCola* &frente, NCola* &fondo);
bool cola_vacia(NCola* frente, NCola* fondo);
void listarMayores(NCola* &frente, NCola* &fondo);


int main(int argc, char *argv[])
{

    srand(time(NULL));

    NCola* frente = NULL;
    NCola* fondo = NULL;
    int edad;
    string nombre;

    for (int i = 0; i < 5; i++){
        Datos persona;
        cout << "Ingrese nombre de la persona: ";
        getline(cin, nombre);
        persona.nombre = nombre;
        cout << "Ingrese edad de la persona: ";
        cin >> edad;
        persona.edad = edad;
        cin.ignore();
        alta_cola(frente, fondo, persona);
    }

    listarMayores(frente, fondo);

    return 0;
}


void alta_cola(NCola* &frente, NCola* &fondo, Datos nuevo_dato){

    NCola* nueva_cola = new(NCola);
    nueva_cola -> dato.edad = nuevo_dato.edad;
    nueva_cola -> dato.nombre = nuevo_dato.nombre;
    nueva_cola -> link = NULL;

    if (frente == NULL){
        frente = nueva_cola;
    } else {
        fondo -> link = nueva_cola;
    }

    fondo = nueva_cola;

}

Datos obtener_cola(NCola* &frente, NCola* &fondo){

    Datos dato = frente -> dato;
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

void listarMayores(NCola* &frente, NCola* &fondo){

    int cont = 0;

    while(!cola_vacia(frente, fondo)){
        Datos aux = obtener_cola(frente, fondo);
        if(aux.edad > 21){
            cont++;
            cout << "La persona " << aux.nombre << " es mayor de 21 anios." << endl;;
        }
    }
    cout << "La cantidad de mayores de 21 anios es de " << cont << " personas." << endl;
}
