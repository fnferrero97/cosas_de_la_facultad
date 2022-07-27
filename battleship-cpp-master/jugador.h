#ifndef JUGADOR_H
#define JUGADOR_H
#include "tableroataques.h"
#include "tablerobarcos.h"

class Jugador {
private:
  TableroBarcos* tableroBarcos;
  TableroAtaques* tableroAtaques;
  Jugador* oponente;
  char* nombre;

public:
  Jugador();
  Jugador(int dimensiones, int maxBarcos, char* nombre);
  ~Jugador();

  void dibujar(bool = true);
  bool agregarBarco(Barco);
  char* getNombre() const;
  bool isGameOver();
  bool recibirAtaque(int, int);
  bool marcarAtaque(int, int);
  void moverLanchas();
};

#endif // JUGADOR_H
