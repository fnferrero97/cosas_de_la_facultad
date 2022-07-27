#ifndef TABLEROATAQUES_H
#define TABLEROATAQUES_H
#include "tablero.h"

class TableroAtaques : public Tablero {
public:
  TableroAtaques();
  TableroAtaques(int);
  bool recibirAtaque(int, int);
};

#endif // TABLEROATAQUES_H
