#include <iostream>
#include <time.h>

using namespace std;

void muestraLlena(int vec[], int cont);


int main(int argc, char *argv[])
{
    int num;

    srand(time(NULL));

    cout << "Ingrese el tamanio del vector: ";
    cin >> num;

    int* p = new int[num];

    muestraLlena(p, num);

    delete[] p;
    p = NULL;


    return 0;
}


void muestraLlena(int vec[], int cont){

    for (int i = 0; i < cont; i++){
        vec[i] = rand()%11+1;
        cout << "El lugar de memoria: " << &vec[i] << " tiene el valor: " << vec[i] << endl;
    }

}
