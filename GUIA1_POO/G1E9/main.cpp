#include <iostream>

using namespace std;

float fibonacciRecursivo(int num);
float fibonacciIterativo(int num);
void fib(int num);

int main(int argc, char *argv[]) {

    int num;
    cout << "Elegi una posicion: ";
    cin >> num;

    cout << endl << "Iterativo" << endl;
    cout << fibonacciIterativo(num) << endl;


    cout << endl << "Recursivo" << endl;
    cout << fibonacciRecursivo(num) << endl << endl;
}


float fibonacciIterativo(int num){

    float ant = 0, antDos = 1, res = 0;

    for (int i = 0; i < num-1; i++){
        res = ant + antDos;
        ant = antDos;
        antDos = res;
    }

    return res;
}

float fibonacciRecursivo(int num){
    if(num == 1 || num == 2){
        return 1;
    } else {
        return fibonacciRecursivo(num-1) + fibonacciRecursivo(num-2);
    }
}
