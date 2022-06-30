#include "sistemaoperativo.h"


sistemaOperativo::sistemaOperativo(std::string nombre){
    this->nombre = nombre;
}

float sistemaOperativo::calcularTamanio(){
    float acum = 0.f;
    for (int i = 0; i < this->carpetas.getTamanio(); i++){
        acum += this->carpetas[i].calcularTamanio();
    }
    return acum;
}

void sistemaOperativo::agregarCarpeta(carpeta carpeta){
    this->carpetas.agregar(carpeta);
}

const std::string &sistemaOperativo::getNombre() const{
    return nombre;
}

std::ostream& operator<<(std::ostream& os, sistemaOperativo& sistema){
    os << "El sistema operativo " << sistema.nombre << " tiene un tamanio de: " << sistema.calcularTamanio() << " y contiene las siguientes carpetas: ";
        for(int i = 0; i < sistema.carpetas.getTamanio(); i++){
            os << sistema.carpetas[i] << "\n";
        }
    return os;
}
