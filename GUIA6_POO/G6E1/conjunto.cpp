#include "conjunto.h"

conjunto::conjunto() : Vector(){}

void conjunto::agregar(const int &ndato){
    try {
        if(!existe(ndato)){
            Vector::agregar(ndato);
        } else {
            throw(ndato);
        }
    } catch(int ndato) {
        std::cout << "El dato " << ndato << " ya se encuentra en el conjunto" << std::endl;
    }
}

bool conjunto::existe(const int &ndato){

    for(int i = 0; i < this->getTamanio(); i++){
        if(this->en(i) == ndato){
            return true;
        }
    }
    return false;
}


