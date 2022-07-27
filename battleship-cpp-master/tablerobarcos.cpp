#include "tablerobarcos.h"

TableroBarcos::TableroBarcos(int dimension, int maxBarcos) : Tablero(dimension) {
  this->cantBarcos = 0;
  this->maxBarcos = maxBarcos;
  this->barcos = this->inicializaBarcos();
}

Barco** TableroBarcos::inicializaBarcos() {
  Barco **arregloBarcos = new Barco *[this->maxBarcos];
  return arregloBarcos;
}

bool TableroBarcos::sePuedeAgregar(Barco barco) {
  if ((barco.getX() < 0 || barco.getY() < 0) ||
      (barco.getX() > dimension || barco.getY() > dimension))
    return false;

  if ((barco.getOrientacion() == 'H' &&
       barco.getX() + barco.getK() > dimension) ||
      (barco.getOrientacion() == 'V' &&
       barco.getY() + barco.getK() > dimension))
    return false;
  /*
    este ciclo verifica a los alrededores del barco
    como el ancho de cada barco es de 1 y si hay que ver a sus dos lados eso
    da un total de 3 espacios en un eje a verificar por eso empieza desde -1
    (una posicion antes) y termina en 1 (una posicion despues) el resto se
    calcula segun la orientacion y sumando y restando 1 para verificar los
    espacios del otro eje
  */
  for (int i = -1; i <= 1; ++i) {
    if (barco.getOrientacion() == 'H') {
      for (int j = barco.getX() - 1; j < (barco.getX() + barco.getK()) + 1;
           j++) {
        if (j >= 0 && matriz[j][barco.getY() + i] != Codigo::Agua)
          return false;
      }
    }
    if (barco.getOrientacion() == 'V') {
      for (int j = barco.getY() - 1; j < (barco.getY() + barco.getK()) + 1; j++)
        if (j >= 0 && matriz[barco.getX() + i][j] != Codigo::Agua)
          return false;
    }
  }
  return true;
}

bool TableroBarcos::agregarBarco(Barco barco) {
  if (this->cantBarcos <= this->maxBarcos && this->sePuedeAgregar(barco)) {
    Barco *upcastingBarco = new Barco(barco);
    this->barcos[cantBarcos] = upcastingBarco;
    if (barco.getOrientacion() == 'H') {
      for (int i = barco.getX(); i < barco.getX() + barco.getK(); i++) {
        matriz[i][barco.getY()] = barco.getCodigo();
      }
    }
    if (barco.getOrientacion() == 'V') {
      for (int i = barco.getY(); i < barco.getY() + barco.getK(); i++) {
        matriz[barco.getX()][i] = barco.getCodigo();
      }
    }
    cantBarcos++;
    return true;
  }
  return false;
}
// booleano si un balco es golpeado o no
bool TableroBarcos::recibirAtaque(int x, int y) {
  int posEnCuerpo = 0;

  this->matriz[x][y] = Codigo::Ataque;

  // agregar daño dentro del cuerpo del barco
  for (int i = 0; i < cantBarcos; i++) {
    if (barcos[i]->getOrientacion() == 'H' && (y == barcos[i]->getY()) &&
        (x >= barcos[i]->getX() &&
         x <= barcos[i]->getX() + barcos[i]->getK())) {
      posEnCuerpo = (x - barcos[i]->getX());
      barcos[i]->golpe(posEnCuerpo);
      return true;
    }
    if (barcos[i]->getOrientacion() == 'V' && (x == barcos[i]->getX()) &&
        (y >= barcos[i]->getY() &&
         y <= barcos[i]->getY() + barcos[i]->getK())) {
      posEnCuerpo = (y - barcos[i]->getY());
      barcos[i]->golpe(posEnCuerpo);
      return true;
    }
  }
  return false;
}

bool TableroBarcos::gameOver() {
  int barcosMuertos = 0;
  for (int i = 0; i < cantBarcos; ++i) {
    if (this->barcos[i]->getGolpes() == this->barcos[i]->getK())
      barcosMuertos++;
  }
  return (barcosMuertos == maxBarcos);
}

void TableroBarcos::info() {
  for (int i = 0; i < cantBarcos; ++i) {
    Barco *barco = barcos[i];
    std::cout << barco->getNombre();
    std::cout << " (" << barco->getX() << "," << barco->getY() << "): ";
    std::cout << barco->getGolpes() << "/" << barco->getK() << " ";
    std::cout << (barco->getIsMuerto() ? "Esta muerto" : "");
    std::cout << "\n";
  }
}

void TableroBarcos::moverLanchas() {
  char lancha[] = "Lancha";
  for (int i = 0; i < maxBarcos; ++i) {
    if (compararChar(barcos[i]->getNombre(), lancha, 6)) {
      int x = (rand() % (this->dimension - 1)) + 1;
      int y = (rand() % (this->dimension - 1)) + 1;
      barcos[i]->setX(x);
      barcos[i]->setY(y);
    }
  }
}
