#include <iostream>
#include "vector.h"

int main(){

    Vector<int> numeros = {1, 2, 3, 4, 6, 10, 25, 26};

    Vector<int> tuvieja2(5);

    for (int i = 0; i < 5; i++){
        tuvieja2[i] = i+1;
    }

//    numeros.agregar(30);
//    numeros.agregar(100);

    for(int n : tuvieja2){
        std::cout << n << "\n";
    }

    return 0;
}
