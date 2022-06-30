#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H
#include <lista.h>


class listaordenada : public lista{
public:
    listaordenada();
    void agregar(const int &);
    void ordenar();
};

#endif // LISTAORDENADA_H
