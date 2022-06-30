#include <iostream>

using namespace std;

int tamanio(char* palabra);
char* agregaAlFinal(char* palabra, char dato);

int main(int argc, char *argv[])
{

    cout << agregaAlFinal("hola", 's') << endl;

    return 0;
}

int tamanio(char* palabra){
    int contador = 0;

    while (palabra[contador] != '\0'){
        contador++;
    }

    return contador;
}

char* agregaAlFinal(char* palabra, char dato){

    int s = tamanio(palabra)+2;
    char* aux = new char[s];

    for (int i = 0; i < s-2; i++){
         aux[i] = palabra[i];
    }

    aux[s-2] = dato;
    aux[s-1] = '\0';

    return aux;

}
