#include <iostream>

using namespace std;

int mcdRecursiva(int a, int b);

int main(int argc, char *argv[])
{
    int a, b;

    cout << "Ingrese el primer numero: ";
    cin >> a;

    cout << "Ingrese el primer numero: ";
    cin >> b;

    cout << "El mcd entre " << a << " y " << b << " es: " << mcdRecursiva(a, b) << endl;

    return 0;
}


int mcdRecursiva(int a, int b){

    if(a == b){
        return a;
    } else if (a > b){
        return mcdRecursiva(a-b, b);
    } else {
        return mcdRecursiva(a, b-a);
    }

}
