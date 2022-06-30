#include <iostream>

using namespace std;

int tamanio(const char* palabra);
char* subCadenaUnParametro(const char* palabra, int pos);

int main(int argc, char *argv[]){


    char* palabra = subCadenaUnParametro("hola", 2);
    cout << palabra << endl;


    delete[] palabra;
    return 0;
}

int tamanio(const char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador+1;
}

char* subCadenaUnParametro(const char* palabra, int pos){

    int s = tamanio(palabra)-pos+1;
    int cant = tamanio(palabra);
    char* aux = new char[s];
    int j = 0;

    for (int i = pos-1; i < cant; i++){
         aux[j] = palabra[i];
         j++;
        }

    return aux;

}
