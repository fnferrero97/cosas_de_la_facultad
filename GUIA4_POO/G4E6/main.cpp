#include <iostream>

using namespace std;

int tamanio(char* palabra);
int cantidadOcurrencias(char* palabra, char dato);
char* eliminaTodaOcurrencia(char* palabra, char dato);

int main(int argc, char *argv[])
{

    cout << eliminaTodaOcurrencia("casa", 'a') << endl;

    return 0;
}

int tamanio(char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador;
}

char* eliminaTodaOcurrencia(char* palabra, char dato){

    int s = tamanio(palabra)-cantidadOcurrencias(palabra, dato)+1;
    int cant = tamanio(palabra);
    char* aux = new char[s];
    int j = 0;

    for (int i = 0; i <= cant; i++){
        if(palabra[i] != dato){
         aux[j] = palabra[i];
         j++;
        }
    }

    return aux;

}

int cantidadOcurrencias(char* palabra, char dato){

    int contador = 0;
    int cant = tamanio(palabra);

    for (int i = 0; i < cant ; i++){
        if (palabra[i] == dato){
            contador++;
        }
    }
    return contador;
}
