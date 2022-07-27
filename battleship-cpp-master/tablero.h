#ifndef TABLERO_H
#define TABLERO_H
#include "info.h"
#include <iomanip>
#include <iostream>

class Tablero {
protected:
  int dimension;
  int** matriz;

public:
  Tablero();
  Tablero(int);
  ~Tablero();

  int** inicializarMatriz(int);
  bool cambiarCasilla(int, int, int);
  void dibujar();
  virtual void info(){};
};

#endif // TABLERO_H
