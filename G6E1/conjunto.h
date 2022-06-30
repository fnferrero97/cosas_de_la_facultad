#ifndef CONJUNTO_H
#define CONJUNTO_H
#include "vector.h"


class conjunto : public Vector<int>{
public:
    conjunto();
    void virtual agregar(const int &);
    bool existe(const int &);
};

#endif // CONJUNTO_H
