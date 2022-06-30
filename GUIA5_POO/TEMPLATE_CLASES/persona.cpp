#include "persona.h"
#include <iostream>

using namespace std;

Persona::Persona(string nombreCompleto, int edad, char sexo){
    this->nombreCompleto = nombreCompleto;
    this->edad = edad;
    this->sexo = sexo;
}

long Persona::getDNI(){
    return this->dni;
}

void Persona::setDNI(long dni){
    this->dni = dni;
}

string Persona::getUniversidad(){
    return this->universidad;
}

void Persona::setUniversidad(string universidad){
    this->universidad = universidad;
}

void Persona::irAClase(int horas){
    (horas > 1)? cout << this->nombreCompleto << " fue a clases por " << horas << " horas." << endl : cout << this->nombreCompleto << " fue a clases por " << horas << " hora." << endl;
}

void Persona::cumplirAnios(){
    this->edad++;
}

void Persona::toString(){
    cout << "Nombre: " << this->nombreCompleto << "\nDNI: " << this->dni << "\nSexo: " << this->sexo << "\nEdad: " << this->edad << "\n";
}
