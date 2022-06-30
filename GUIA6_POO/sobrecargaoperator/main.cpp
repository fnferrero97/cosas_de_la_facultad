#include "vector.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    Vector<int> v1;
    Vector<int> v2;

    for(int i = 0; i < 5; i++){
        v1.agregar(i);
        v2.agregar(i+5);
    }

    Vector<int> v3 = v1 + v2;

//    for (int i = 0; i < v3.getTamanio(); i++){
//        cout << v3[i] << " ";
//    }

    cout << v3;

    return 0;
}

