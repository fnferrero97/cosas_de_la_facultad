#include <iostream>

using namespace std;

int tamanio(char* palabra);
int posOcurrencia(char* palabra, char dato);
char* eliminaUnaOcurrencia(char* palabra, char dato);

int main(int argc, char *argv[])
{

    cout << eliminaUnaOcurrencia("perro", 'r') << endl;

    return 0;
}

int tamanio(char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador;
}

char* eliminaUnaOcurrencia(char* palabra, char dato){

    int s = tamanio(palabra);
    char* aux = new char[s];
    int j = 0;

    for (int i = 0; i <= s; i++){
        if(i != posOcurrencia(palabra, dato)){
         aux[j] = palabra[i];
         j++;
        }
    }

    return aux;

}

int posOcurrencia(char* palabra, char dato){

    for (int i = 0; i < tamanio(palabra); i++){
        if (palabra[i] == dato){
            return i;
        }
    }
    return -1;
}
