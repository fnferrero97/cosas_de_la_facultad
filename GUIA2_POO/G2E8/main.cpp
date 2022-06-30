#include <iostream>
#include <string>


using namespace std;

void intercambio(string array_str[], int array_1[], int array_2[], int cont, int indice = 0);

int main(int argc, char *argv[])
{
    int array_1[] = {1, 2, 3, 4};
    int array_2[] = {5, 6, 7, 8};
    string array_str[4] = {""};

    int tamanio = (sizeof(array_1) / sizeof(int));

    intercambio(array_str, array_1, array_2, tamanio-1);

    cout << " --- ARREGLO CONCATENADO ---" << endl;

    for (int i = 0; i < tamanio; i++){
        cout << array_str[i] << " ";
    }

    cout << endl;

    return 0;
}

void intercambio(string array_str[], int array_1[], int array_2[], int cont, int indice){

    if (indice <= cont){
        array_str[indice] = to_string(array_1[indice]) + to_string(array_2[indice]);
        return intercambio(array_str, array_1, array_2, cont, indice+1);
        }

   }
