#ifndef JUEGO_H
#define JUEGO_H
#include "info.h"
#include "jugador.h"
#include "lancha.h"
#include "portaaviones.h"
#include "submarino.h"
#include <cstdlib>

class Juego {
private:
  class Jugador* jugador;
  class Jugador* IA;
  int dimensiones, maxBarcos;
  bool colocacionAleatoria;
  bool turno;
  bool debugMode;
  char* nombreJugador;
  char* infoBarco = "1: Lancha       (Tamanio = 1)\n"
                    "2: Crucero      (Tamanio = 3)\n"
                    "3: Submarino    (Tamanio = 3)\n"
                    "4: Destructor   (Tamanio = 4)\n"
                    "5: Portaaviones (Tamanio = 5)\n";
public:
  Juego(bool = false);
  ~Juego(){};

  void iniciar();
  void inicializarConfiguracion();
  void actualizar();

  // Colocacion de barcos
  bool colocarBarcosManual();
  bool colocarBarcosAleatorio(int);
  bool colocarBarcos(class Jugador*, int, int, int, char);

  // Ataques
  bool atacarIA(int, int);
  bool atacarJugador();

  // mover la lancha en cada turno
  void moverLanchas();

  // dibujado
  void limpiarPantalla();
  void dibujar();
  void infoAtaques(bool, bool);

  /*
    1.iniciarConfiguracion()
      cantidad de barcos, alto y ancho del tablero
    2.colocarBarcosManual() o colocarBarcorAleatorio()

    3.actualizar()
      while(!isGameOverIA && !isGamerOverJugador){
        bool ataqueExitoso;
        if(turno::Jugador)
          ataqueExitoso = atacarIA() {pedir (x,y)}
        else
          ataqueExitoso = atacarJugador() {aleatorio (x,y)}

        if(ataqueExitoso && turno::Jugador) "Jugador acerto Atauqe"
        if(ataqueExitoso && turno::IA) "IA acerto Atauqe"

        moverLanchas() {busca todas las lanchas y las mueve}
      }
      if(isGameOverIA) "gano Jugador"
      if(isGameOverJugador) "gano IA"


  */
};

#endif // JUEGO_H
