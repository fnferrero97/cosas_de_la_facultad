#ifndef GASTOSERVICIO_H
#define GASTOSERVICIO_H
#include "gasto.h"

class gastoServicio : public gasto{
public:
    gastoServicio(std::string, float);
    void mostrarDetalle();
};

#endif // GASTOSERVICIO_H
