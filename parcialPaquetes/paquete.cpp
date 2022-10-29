#include "paquete.h"


Paquete::Paquete(){}

Paquete::Paquete(std::string codigo, std::string nombre, int version){
    this->codigo = codigo;
    this->nombre = nombre;
    this->version = version;
}

void Paquete::agregarDependencia(Paquete* dependencia){
    this->dependencias.push_back(dependencia);
}

const std::string &Paquete::getCodigo() const{
    return codigo;
}

void Paquete::setCodigo(const std::string &codigo){
    this->codigo = codigo;
}

const std::string &Paquete::getNombre() const{
    return nombre;
}

void Paquete::setNombre(const std::string &nombre){
    this->nombre = nombre;
}

int Paquete::getVersion() const{
    return version;
}

void Paquete::setVersion(int version){
    this->version = version;
}

const std::vector<Paquete*> &Paquete::getDependencias() const{
    return dependencias;
}

bool Paquete::noTieneDependencias(){
    return this->dependencias.size() == 0;
}

bool Paquete::noTieneTransitiva(){

    for (size_t i = 0; i < this->dependencias.size(); i++){
        if (!this->dependencias[i]->noTieneDependencias()) return false;
    }

    return true;
}

std::ostream& operator<<(std::ostream& os, Paquete*& otroPaquete){
    os << otroPaquete->getNombre() << "\n";

    if (otroPaquete->noTieneDependencias()) return os;

    for (size_t i = 0; i < otroPaquete->dependencias.size(); i++){
        os << "   " << otroPaquete->dependencias[i];
        os << "   ";
    }

    return os;
}
