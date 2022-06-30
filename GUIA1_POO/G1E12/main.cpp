#include <iostream>
#include <time.h>

using namespace std;

bool esPrimo(int num, int chequea = 2);

int main(int argc, char *argv[])
{
    int num, cont = 0;

    cout << "Ingrese hasta que numero quiere buscar: ";
    cin >> num;

    cout << "Los numeros primos hasta el numero " << num << " son:" << endl;

    for (int i = 1; i < num+1; i++){
        if(esPrimo(i)){
            cont++;
            cout << i << " - ";
        }
    }

    cout << endl << "Para un total de: " << cont << " numeros." << endl;

    return 0;
}


bool esPrimo(int num, int chequea){

    if(num == 1 || num == 2){
        return true;
    }
    else if(num % chequea == 0 && num != chequea){
        return false;
    }
    else if(num == chequea){
        return true;
    }
    else {
        return esPrimo(num, chequea+1);
    }
}

