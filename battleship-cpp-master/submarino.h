#ifndef SUBMARINO_H
#define SUBMARINO_H
#include "barco.h"

class Submarino : public Barco {
public:
  Submarino(){};

  Submarino(int x, int y, char orientacion) : Barco(x, y, 3, orientacion, "Submarino") {
    this->codigo = Codigo::Submarino;
  };

};

#endif // SUBMARINO_H
