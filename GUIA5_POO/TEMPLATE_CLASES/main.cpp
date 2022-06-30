#include <iostream>
#include "persona.h"

using namespace std;


int main(int argc, char *argv[]){

    Persona* p1 = new Persona("Facundo", 25, 'M');

    p1->setDNI(40160593);
    p1->altura = 1.87;
    p1->peso = 101;
    p1->toString();
    p1->irAClase(1);

    cout << endl;

    p1->irAClase(12);
    p1->cumplirAnios();
    p1->toString();

    delete p1;
}
