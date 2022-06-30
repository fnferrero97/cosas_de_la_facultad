#include <iostream>

using namespace std;

bool esPrimo(int num, int chequa = 2);

int main(int argc, char *argv[]) {

    int num;

    cout << "Elegi un numero: ";
    cin >> num;

    if(esPrimo(num))
        cout << "SI es primo." << endl;
    else
        cout << "NO es primo." << endl;
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
