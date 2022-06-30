#ifndef MAZO_H
#define MAZO_H
#include <time.h>
#include "listacircular.h"
#include "carta.h"

class mazo{
private:
    std::string palos[4] = {"Basto", "Espada", "Oro", "Copa"};
    int valores[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12};
    ListaCircular<carta> cartas;
    void intercambiar(int, int);
public:
    mazo();
    void mostrar();
    void mezclar(int);
    void repartir();
    friend std::ostream& operator<<(std::ostream&, mazo&);
};

#endif // MAZO_H
