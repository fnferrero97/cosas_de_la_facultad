#include <iostream>

using namespace std;

bool esPalindromo(int arr[], int com, int final);

int main(int argc, char *argv[])
{
    int array[] = {3, 4, 1, 1 , 4, 3};
    int tamanio = (sizeof(array) / sizeof(int));

    if(esPalindromo(array, 0, tamanio-1)){
        cout << "El arreglo SI es un palindromo" << endl;
    } else {
        cout << "El arreglo NO es un palindromo" << endl;
    }


    cout << endl;
    return 0;
}


bool esPalindromo(int arr[], int com, int final){

    if (com >= final){
        return true;
    } else if (arr[com] == arr[final]){
        esPalindromo(arr, com+1, final-1);
    } else {
        return false;
    }

}
