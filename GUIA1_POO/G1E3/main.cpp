#include <iostream>
#include <string>

using namespace std;

const int EDAD_MINIMA = 12;
const int EDAD_MAXIMA = 90;
const int CANT_INTEGRANTES = 5;

bool valida_edad(int edad);
void ordena(int arreglo[], string nombres[], int tamanio);

int main(int argc, char *argv[]) {

    int edad, contador = 0;
    string nombre;
    int edades[CANT_INTEGRANTES] = {0};
    string nombres[CANT_INTEGRANTES] = {"a"};


    while(contador < CANT_INTEGRANTES){

    cout << "Ingrese el nombre de la persona: ";
    getline(cin, nombre);
    cout << "Ingrese la edad de la persona: ";
    cin >> edad;
    cin.ignore();
    cout << "----------------" << endl;

    if (valida_edad(edad)){
        nombres[contador] = nombre;
        edades[contador] = edad;
        contador++;
        }
        else {
        cout << "Esa edad no es correcta, ingrese nuevamente. \n";
        }
    }

    ordena(edades, nombres, contador);

    cout << "El integrante de mayor edad es: " << nombres[0] << " con la edad de: " << edades[0] << endl;

    return 0;
}

void ordena(int edades[], string nombres[], int tamanio){

    string s_aux;
    int i_aux;

    for (int i = 0; i<(tamanio-1); i++){
        for (int j = i+1; j<tamanio; j++){
            if (edades[i] < edades[j])
            {
                s_aux = nombres[i];
                nombres[i] = nombres[j];
                nombres[j] = s_aux;

                i_aux = edades[i];
                edades[i] = edades[j];
                edades[j] = i_aux;
            }
        }
    }
}

bool valida_edad(int edad){
    return (edad >= EDAD_MINIMA) && (edad <= EDAD_MAXIMA);
}
