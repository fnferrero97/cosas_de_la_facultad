#include "datas.h"

datas::datas(std::string nombre){
    this->nombre = nombre;
}

const std::string& datas::getNombre() const{
    return nombre;
}
