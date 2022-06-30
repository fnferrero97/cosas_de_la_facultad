#include "carpeta.h"


carpeta::carpeta(std::string nombre) : datas(nombre) {}

float carpeta::calcularTamanio(){
    float acum = 0.f;
    for (int i = 0; i < this->archivos.getTamanio(); i++){
        acum += (*this->archivos[i]).calcularTamanio();
    }
    return acum;
}

void carpeta::agregarArchivo(datas* data){
    this->archivos.agregar(data);
}

const std::string &carpeta::getNombre() const{
    return datas::getNombre();
}


std::ostream& operator<<(std::ostream& os, carpeta& carpeta){
    os << "La carpeta: " << carpeta.getNombre() << " tiene los siguientes archivos: " << "\n";

    for(int i = 0; i < carpeta.archivos.getTamanio(); i++){
        os << carpeta.archivos[i];
    }

    return os;
}
