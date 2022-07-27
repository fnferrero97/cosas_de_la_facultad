#ifndef TABLEROBARCOS_H
#define TABLEROBARCOS_H
#include "barco.h"
#include "tablero.h"
#include <cstdlib>

class TableroBarcos : public Tablero {
private:
  int cantBarcos, maxBarcos;
  Barco** barcos;

public:
  TableroBarcos(){};
  TableroBarcos(int, int);
  ~TableroBarcos(){};

  Barco **inicializaBarcos();
  bool sePuedeAgregar(Barco);
  bool agregarBarco(Barco);
  bool recibirAtaque(int, int);
  bool gameOver();
  void info();
  void moverLanchas();

  bool compararChar(char *char1, char *char2, int tamaño) {
    for (int i = 0; i < tamaño; ++i)
      if (char1[i] != char2[i])
        return false;
    return true;
  }
};

#endif // TABLEROBARCOS_H
