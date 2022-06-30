#ifndef GASTO_H
#define GASTO_H
#include <string>
#include <iostream>

class gasto{
private:
    float valor;
    std::string detalle;
public:
    gasto(std::string, float);
    virtual ~gasto();
    float getValor() const;
    const std::string& getDetalle() const;
    void virtual mostrarDetalle() = 0;
};

#endif // GASTO_H
