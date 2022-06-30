#ifndef GASTOEXTRAORDINARIO_H
#define GASTOEXTRAORDINARIO_H
#include "gasto.h"

class gastoExtraordinario : public gasto{
public:
    gastoExtraordinario(std::string, float);
    void mostrarDetalle();
};

#endif // GASTOEXTRAORDINARIO_H
