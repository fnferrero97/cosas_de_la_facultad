#include <iostream>

using namespace std;

int tamanio(char* palabra);
int posOcurrencia(char* palabra, char dato);

int main(int argc, char *argv[])
{
    char palabra[] = "perro";
    cout << posOcurrencia(palabra, 'e') << endl;

    return 0;
}

int tamanio(char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador;
}


int posOcurrencia(char* palabra, char dato){

    for (int i = 0; i < tamanio(palabra); i++){
        if (palabra[i] == dato){
            return i;
        }
    }
    return -1;
}
