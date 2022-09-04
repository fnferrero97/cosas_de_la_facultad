#include "agenda.h"

Agenda::Agenda(){}

void Agenda::agregarPersona(Persona p){
    this->lista.push_back(p);
}

float Agenda::buscarTelefono(char* nombre, char* apellido){
    for (Persona p : this->lista){
        if (p.getNombre() == nombre && p.getApellido() == apellido) return p.getTelefono();
    }
}

const std::vector<Persona>& Agenda::getLista() const{
    return lista;
}

