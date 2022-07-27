#include "jugador.h"

Jugador::Jugador(int dimensiones, int maxBarcos, char *nombre) {
  this->tableroBarcos = new TableroBarcos(dimensiones, maxBarcos);
  this->tableroAtaques = new TableroAtaques(dimensiones);
  this->nombre = nombre;
}

void Jugador::dibujar(bool informacion) {
  std::cout << "TUS ATAQUES\n";
  tableroAtaques->dibujar();
  std::cout << "TUS BARCOS\n";
  tableroBarcos->dibujar();
  if (informacion)
    tableroBarcos->info();
}

bool Jugador::agregarBarco(Barco barco) {
  return tableroBarcos->agregarBarco(barco);
}

char* Jugador::getNombre() const { return nombre; }

bool Jugador::isGameOver() { return this->tableroBarcos->gameOver(); }

bool Jugador::recibirAtaque(int x, int y) {
  return this->tableroBarcos->recibirAtaque(x, y);
}

bool Jugador::marcarAtaque(int x, int y) {
  return this->tableroAtaques->recibirAtaque(x, y);
}

void Jugador::moverLanchas() { this->tableroBarcos->moverLanchas(); }
