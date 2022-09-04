#include "factura.h"


Factura::Factura(){}

Factura::Factura(char* nombre, float mes, float tiempo, float giga){
    this->nombre = nombre;
    this->montoxmes = mes;
    this->montoxtiempo = tiempo;
    this->montoxgiga = giga;
}

char* Factura::getnombre() const{
    return nombre;
}

void Factura::setNombre(char *Nombre){
    nombre = Nombre;
}

float Factura::getmontoxmes() const{
    return montoxmes;
}

void Factura::setMontoxmes(float Montoxmes){
    montoxmes = Montoxmes;
}

float Factura::getmontoxtiempo() const{
    return montoxtiempo;
}

void Factura::setMontoxtiempo(float Montoxtiempo){
    montoxtiempo = Montoxtiempo;
}

float Factura::getmontoxgiga() const{
    return montoxgiga;
}

void Factura::setMontoxgiga(float Montoxgiga){
    montoxgiga = Montoxgiga;
}
