#include <iostream>

using namespace std;

int tamanio(char* palabra);
char* agregaAlInicio(char* palabra, char dato);

int main(int argc, char *argv[])
{

    cout << agregaAlInicio("ola", 'h') << endl;

    return 0;
}

int tamanio(char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador;
}

char* agregaAlInicio(char* palabra, char dato){

    int s = tamanio(palabra)+2;
    char* aux = new char[s];

    for (int i = 0; i < s-1; i++){
         aux[i+1] = palabra[i];
    }

    aux[0] = dato;
    aux[s] = '\0';

    return aux;

}
