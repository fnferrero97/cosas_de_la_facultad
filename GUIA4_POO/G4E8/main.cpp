#include <iostream>

using namespace std;

int tamanio(char* palabra);
char* subCadenaDosParametro(const char* palabra, int pos1, int pos2);

int main(int argc, char *argv[])
{
    char* palabra = subCadenaDosParametro("palabra", 2, 5);
    cout << palabra << endl << endl;

    delete[] palabra;
    return 0;
}

int tamanio(char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador;
}

char* subCadenaDosParametro(const char* palabra, int pos1, int pos2){

    int s = pos2-pos1+1;
    char* aux = new char[s];
    int j = 0;

    for (int i = pos1-1; i <= pos2-1; i++){
         aux[j] = palabra[i];
         j++;
        }

    aux[s] = '\0';

    return aux;
}
