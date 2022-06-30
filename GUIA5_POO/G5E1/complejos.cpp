#include "complejos.h"
#include <iostream>

Complejo::Complejo(){}

Complejo::Complejo(int parteReal, int parteImaginaria){
    this->parteReal = parteReal;
    this->parteImaginaria = parteImaginaria;
}

Complejo Complejo::suma(Complejo complejo){
    Complejo suma(this->getParteReal() + complejo.getParteReal(), this->getParteImaginaria() + complejo.getParteImaginaria());
    return suma;
}

Complejo Complejo::resta(Complejo complejo){
    Complejo resta(this->getParteReal() - complejo.getParteReal(), this->getParteImaginaria() - complejo.getParteImaginaria());
    return resta;
}

Complejo Complejo::multiplicar(Complejo complejo){
    int t1 = this->getParteReal() * complejo.getParteReal();
    int t2 = this->getParteReal() * complejo.getParteImaginaria();
    int t3 = this->getParteImaginaria() * complejo.getParteReal();
    int t4 = (this->getParteImaginaria() * complejo.getParteImaginaria()) * -1;

    int real = t1 + t4;
    int compleja = t2 + t3;

    Complejo mult(real, compleja);
    return mult;
}

Complejo Complejo::dividir(Complejo complejo){
    int t1 = this->getParteReal() * complejo.getParteReal();
    int t2 = this->getParteReal() * complejo.getParteImaginaria();
    int t3 = this->getParteImaginaria() * complejo.getParteReal();
    int t4 = (this->getParteImaginaria() * complejo.getParteImaginaria()) * -1;
    int t5 = complejo.getParteReal() * complejo.getParteReal();
    int t6 = ((complejo.getParteImaginaria() * complejo.getParteImaginaria()) * -1) * -1;

    int realArriba = t1 + t4;
    int complejaArriba = t2 + t3;
    int realAbajo = t5 + t6;

    Complejo div(realArriba, complejaArriba);
    div.setDenominador(realAbajo);
    return div;
};

int Complejo::getParteReal(){
    return this->parteReal;
}

int Complejo::getParteImaginaria(){
    return this->parteImaginaria;
}

int Complejo::getDenominador(){
    return this->denominador;
}

void Complejo::setDenominador(int denominador){
    this->denominador = denominador;
}

int Complejo::mcd(int a, int b){
   return a%b == 0? b : mcd(b, a%b);
}

void Complejo::mostrarFraccion(){

    int mcA = mcd(this->getParteReal(), this->getDenominador());
    int mcB = mcd(this->getParteImaginaria(), this->getDenominador());

    std::cout << this->getParteReal() / mcA << "/" << this->getDenominador() / mcA << " + " << this->getParteImaginaria() / mcB << "i/" << this->getDenominador() / mcB << "\n";
}

std::ostream &operator<< (std::ostream &out, Complejo &complejo){
    if(complejo.parteImaginaria < 0){
      return out << complejo.parteReal << " - " << complejo.parteImaginaria * -1 << "i";
    } else {
      return out << complejo.parteReal << " + " << complejo.parteImaginaria << "i";
    }
}
