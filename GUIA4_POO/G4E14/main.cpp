#include <iostream>

using namespace std;

int tamanio(const char* palabra);
char* cadenaAlReverso(const char* palabra);

int main(int argc, char *argv[])
{
    char* palabra = cadenaAlReverso("palabra");
    cout << palabra << endl << endl;

    delete[] palabra;
    return 0;
}

int tamanio(const char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador;
}

char* cadenaAlReverso(const char* palabra){

    int s = tamanio(palabra);
    char* aux = new char[s+1];
    int j = 0;

    for (int i = s-1; i >= 0; i--){
         aux[j] = palabra[i];
         j++;
        }

    aux[s] = '\0';

    return aux;
}
