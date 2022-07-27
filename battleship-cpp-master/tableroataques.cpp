#include "tableroataques.h"

TableroAtaques::TableroAtaques(int dimension) : Tablero(dimension) {}

bool TableroAtaques::recibirAtaque(int x, int y) {
  this->matriz[x][y] = Codigo::Ataque;
  return true;
}
