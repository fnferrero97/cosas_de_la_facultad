#ifndef LANCHA_H
#define LANCHA_H
#include "barco.h"

class Lancha : public Barco {
public:
  Lancha(){};

  Lancha(int x, int y, char orientacion) : Barco(x, y, 1, orientacion, "Lancha") {
    this->codigo = Codigo::Lancha;
  };

  void actualizar(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

#endif // LANCHA_H
