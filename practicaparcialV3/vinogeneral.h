#ifndef VINOGENERAL_H
#define VINOGENERAL_H
#include <string.h>

class vinoGeneral{
private:
    int nro;
    float litros;
    int anioProduccion;
    char tipo;
public:
    vinoGeneral(int, float, char, int);
    float virtual calcularPrecio() = 0;
    bool virtual sePuedeVender(int) = 0;
    float getLitros() const;
    int getNro() const;
    void setNro(int nro);
    void setLitros(float litros);
    int getAnioProduccion() const;
    void setAnioProduccion(int anioProduccion);
    int virtual getTipo() = 0;
};

#endif // VINOGENERAL_H
