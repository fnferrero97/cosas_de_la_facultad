#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <ostream>

class Complejo{
private:
       int parteReal;
       int parteImaginaria;
       int denominador = 1;
       int getDenominador();
       void setDenominador(int);
       int mcd(int, int);
public:
    Complejo();
    Complejo(int, int);
    Complejo suma(Complejo);
    Complejo resta(Complejo);
    Complejo multiplicar(Complejo);
    Complejo dividir(Complejo);
    int getParteReal();
    int getParteImaginaria();
    void mostrarFraccion();
    friend std::ostream &operator<<(std::ostream&, Complejo&);
};

#endif // COMPLEJO_H
