#ifndef LISTA_H
#define LISTA_H
#include "vector.h"


class lista : public Vector<int>
{
public:
    lista();
    void virtual agregar(const int &);
};

#endif // LISTA_H
