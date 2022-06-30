#ifndef CONJUNTOORDENADO_H
#define CONJUNTOORDENADO_H
#include "conjunto.h"


class conjuntoordenado : public conjunto
{
public:
    conjuntoordenado();
    void agregar(const int &);
    void ordenar();
};

#endif // CONJUNTOORDENADO_H
