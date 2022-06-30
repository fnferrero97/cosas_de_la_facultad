#include <iostream>

using namespace std;

int potencia(int num, int pot);


int main(int argc, char *argv[]) {

    int num, pot;

    cout << "Elegi un numero: ";
    cin >> num;

    cout << "Elegi una potencia: ";
    cin >> pot;

    cout << num << " a la " << pot << " potencia es: " << potencia(num, pot) << endl;
}

int potencia(int num, int pot){
    if(pot == 0){
        return 1;
    } else {
        return num * potencia(num, pot-1);
    }
}
