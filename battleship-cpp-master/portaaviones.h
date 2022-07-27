#ifndef PORTAAVIONES_H
#define PORTAAVIONES_H
#include "barco.h"

class Portaaviones : public Barco {
public:
  Portaaviones(){};

  Portaaviones(int x, int y, char orientacion) : Barco(x, y, 5, orientacion, "Portaavion") {
    this->codigo = Codigo::Portaaviones;
  };
};

#endif // PORTAAVIONES_H
