#include "juego.h"

Juego::Juego(bool debugMode) {
  std::cout << "------------BATALLA NAVAL------------\n\npowered by JoacoScript\n\n";
  this->inicializarConfiguracion();
  this->debugMode = debugMode;
  srand(time(NULL));
}

void Juego::iniciar() {
  // colocacion de barcos del jugador
  this->colocacionAleatoria ? this->colocarBarcosAleatorio(Turno::Jugador) : this->colocarBarcosManual();

  // colocacion de barcos de la IA
  this->colocarBarcosAleatorio(Turno::IA);

  int continuar = 0;
  while (continuar != 1) {
    this->limpiarPantalla();
    this->dibujar();
    std::cout << "\nAsi quedara su tablero\n"
              << "Ingrese 1 para continuar... ";
    std::cin >> continuar;
  }

  this->limpiarPantalla();
  this->actualizar();
}

void Juego::inicializarConfiguracion() {
  std::cout << "Parametros iniciales:\n";
  std::cout << "Alto y ancho del tablero: ";
  std::cin >> this->dimensiones;
  std::cout << "Cantidad de barcos con los que vas a jugar: ";
  std::cin >> this->maxBarcos;
  std::cout << "Colorcar barcos de forma manual o aleatoria (0: Manual, 1: "
               "Aleatoria): ";
  std::cin >> this->colocacionAleatoria;

  this->turno = Turno::Jugador;
  this->jugador = new class Jugador(dimensiones, maxBarcos, "Jugador");
  this->IA = new class Jugador(dimensiones, maxBarcos, "IA");
}

void Juego::actualizar() {
  this->dibujar();
  bool isContinuar = true;
  bool ataqueJugadorExitoso;
  bool ataqueIAExitoso;
  int x, y;

  std::cout << "Ingrese coordenada en X: ";
  std::cin >> x;
  std::cout << "Ingrese coordenada en Y: ";
  std::cin >> y;

  while (isContinuar) {
    ataqueJugadorExitoso = this->atacarIA(x, y);
    ataqueIAExitoso = this->atacarJugador();

    this->limpiarPantalla();
    // informa a los usuarios sobre los ataques exitosos;

    isContinuar = !jugador->isGameOver() && !IA->isGameOver();
    if (isContinuar) {
      this->dibujar();
      this->infoAtaques(ataqueJugadorExitoso, ataqueIAExitoso);
      // this->moverLanchas();

      std::cout << "Ingrese coordenada en X:\n";
      std::cin >> x;
      std::cout << "Ingrese coordenada en Y:\n";
      std::cin >> y;
    }

    this->limpiarPantalla();
  }

  this->limpiarPantalla();

  if (jugador->isGameOver())
    std::cout << "Perdiste :(\n";
  else if (IA->isGameOver())
    std::cout << "Ganaste!!!\n";
  this->dibujar();
}

bool Juego::colocarBarcosManual() {
  int i = 0;
  bool colocacionExitosa = true;
  int opcionBarco, x, y;
  char orientacion;
  std::cout << infoBarco;

  while (i < this->maxBarcos) {
    this->limpiarPantalla();
    this->dibujar();

    if (!colocacionExitosa) {
       std::cout << "Error en algún parametro. Ingrese nuevamente\n";
    }

    std::cout << "Barco a agregar (1,2,3,4,5): ";
    std::cin >> opcionBarco;
    std::cout << "Posicion en x: ";
    std::cin >> x;
    std::cout << "Posicion en y: ";
    std::cin >> y;
    std::cout << "Orientacion (H: horizontal, V: vertical): ";
    std::cin >> orientacion;


    colocacionExitosa = this->colocarBarcos(this->jugador, opcionBarco, x, y, orientacion);

    if (colocacionExitosa) i++;
  }
  return true;
}

bool Juego::colocarBarcosAleatorio(int turno) {
  int i = 0;
  bool colocacionExitosa = true;
  while (i < maxBarcos) {
    int opcionBarco = (rand() % 5) + 1;
    int x = (rand() % (this->dimensiones - 1)) + 1;
    int y = (rand() % (this->dimensiones - 1)) + 1;
    char orientacion = (rand() % 2) == 1 ? 'H' : 'V';

    class Jugador *jugadorConTurno =
        (turno == Turno::Jugador) ? this->jugador : this->IA;

    colocacionExitosa =
        this->colocarBarcos(jugadorConTurno, opcionBarco, x, y, orientacion);

    if (colocacionExitosa)
      i++;
  }
  return true;
}

bool Juego::colocarBarcos(class Jugador *jugadorConTurno, int opcion, int x,
                          int y, char orientacion) {
  if (opcion == 1) {
    class Lancha lancha(x, y, orientacion);
    return jugadorConTurno->agregarBarco(lancha);
  }
  if (opcion == 2) {
    class Submarino sub(x, y, orientacion);
    return jugadorConTurno->agregarBarco(sub);
  }
  if (opcion == 3) {
    class Submarino sub(x, y, orientacion);
    return jugadorConTurno->agregarBarco(sub);
  }
  if (opcion == 4) {
    class Submarino sub(x, y, orientacion);
    return jugadorConTurno->agregarBarco(sub);
  }
  if (opcion == 5) {
    class Portaaviones porta(x, y, orientacion);
    return jugadorConTurno->agregarBarco(porta);
  }
  return false;
}

bool Juego::atacarIA(int x, int y) {
  jugador->marcarAtaque(x, y);
  return IA->recibirAtaque(x, y);
}

bool Juego::atacarJugador() {
  int x = rand() % this->dimensiones;
  int y = rand() % this->dimensiones;
  IA->marcarAtaque(x, y);
  return jugador->recibirAtaque(x, y);
}

void Juego::moverLanchas() {
  this->jugador->moverLanchas();
  this->IA->moverLanchas();
}

void Juego::dibujar() {
  std::cout << "Tu tablero\n" << this->infoBarco;
  this->jugador->dibujar();
  if (debugMode) {
    std::cout << "Tablero de la IA\n";
    this->IA->dibujar();
  }
}

void Juego::infoAtaques(bool ataqueJugadorExitoso, bool ataqueIAExitoso) {
  std::cout << "\n";
  if (ataqueJugadorExitoso)
    std::cout << "Ataque hacia enemigo exitoso!!\n";
  else
    std::cout << "Ataque hacia enemigo fallido!!\n";

  if (ataqueIAExitoso)
    std::cout << "Ataque del enemigo exitoso!\n";
  else
    std::cout << "Ataque del enemigo fallido!!\n";
  std::cout << "\n";
}

void Juego::limpiarPantalla() {
#ifdef _WIN32
  std::system("cls");
#elif __unix__
  std::system("clear");
#endif
}
