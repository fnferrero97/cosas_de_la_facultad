#include "conjuntoordenado.h"

conjuntoordenado::conjuntoordenado() : conjunto(){}

void conjuntoordenado::agregar(const int &ndato){
     conjunto::agregar(ndato);
     this->ordenar();
}

void conjuntoordenado::ordenar(){

    int aux;

    for (int i = 0; i < this->getTamanio()-1; i++){
        for (int j = i+1; j < this->getTamanio(); j++){
            if(this->en(i) > this->en(j)){
                aux = this->en(i);
                this->en(i) = this->en(j);
                this->en(j) = aux;
            }
        }
    }

}
