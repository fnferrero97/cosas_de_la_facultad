#include <iostream>
#include <time.h>

using namespace std;

int mcdRecursivo(int a, int b);

int main(int argc, char *argv[])
{

    int n1, n2;

    cout << "Ingrese numero 1: ";
    cin >> n1;

    cout << "Ingrese numero 2: ";
    cin >> n2;

    cout << mcdRecursivo(n1, n2) << endl;

    return 0;
}

int mcdRecursivo(int a, int b){

    return (a % b == 0) ? b : mcdRecursivo(b, a%b);

}
