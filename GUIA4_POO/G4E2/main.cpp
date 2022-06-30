#include <iostream>

using namespace std;

int tamanio(char* palabra);
char* aMinuscula(char* palabra);

int main(int argc, char *argv[])
{

    cout << aMinuscula("hOla PeRrO") << endl;

    return 0;
}

int tamanio(char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador;
}

char* aMinuscula(char* palabra){

    int s = tamanio(palabra);

    char* aux = new char[s];

    for (int i = 0; i <= s; i++){
        if(palabra[i] >= 'A' && palabra[i] <= 'Z'){
            aux[i] = palabra[i] + 32;
        } else {
            aux[i] = palabra[i];
        }
    }
    return aux;

}
