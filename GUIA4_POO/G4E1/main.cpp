#include <iostream>

using namespace std;

int tamanio(char* palabra);
char* aMayuscula(char* palabra);

int main(int argc, char *argv[])
{

    cout << aMayuscula("hOla PeRrO") << endl;

    return 0;
}

int tamanio(char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador;
}

char* aMayuscula(char* palabra){

    int s = tamanio(palabra);

    char* aux = new char[s];

    for (int i = 0; i <= s; i++){
        if(palabra[i] >= 'a' && palabra[i] <= 'z'){
            aux[i] = palabra[i] - 32;
        } else {
            aux[i] = palabra[i];
        }
    }
    return aux;

}
