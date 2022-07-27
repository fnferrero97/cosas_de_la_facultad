#include "barco.h"
#include <iostream>

Barco::Barco(int x, int y, int k, char orientacion, char *nombre) {
  this->x = x;
  this->y = y;
  this->k = k;
  this->orientacion = orientacion;
  this->nombre = nombre;
  this->isMuerto = false;
  this->golpes = 0;
  this->cuerpo = inicializaCuerpo();
}

Barco::~Barco() {}

int *Barco::inicializaCuerpo() {
  int *cuerpo = new int[k];
  for (int x = 0; x < k; ++x) {
    cuerpo[x] = Codigo::Sano;
  }
  return cuerpo;
}

bool Barco::compararChar(char* char1, char* char2, int tamaño) {
  for (int i = 0; i < tamaño; ++i)
    if (char1[i] != char2[i]) return false;
  return true;
}

bool Barco::golpe(int x) {
  // si el golpe se hizo dentro del rango de su longitud
  if (x > k || this->cuerpo[x] == Codigo::Dañado)
    return false;

  char submarino[] = "submarino";
  // cambia la logica del submarino, no use polimorfismo porque no funcionaba
  // (SOLUCIONAR)
  if (this->compararChar(this->getNombre(), submarino, 9) && x == 1) {
    for (int i = 0; i < k; ++i) {
      this->cuerpo[i] = Codigo::Dañado;
      this->golpes = 3;
    }
  } else {
    this->cuerpo[x] = Codigo::Dañado;
    this->golpes++;
  }

  if (this->golpes == this->k) {
    this->isMuerto = true;
    return true;
  }
  return false;
}

int Barco::getX() const { return x; }

int Barco::getY() const { return y; }

int Barco::getK() const { return k; }

char Barco::getOrientacion() const { return orientacion; }

char *Barco::getNombre() const { return nombre; }

int Barco::getCodigo() const { return codigo; }

int Barco::getGolpes() const { return golpes; }

bool Barco::getIsMuerto() const { return isMuerto; }

void Barco::setX(int newX) { x = newX; }

void Barco::setY(int newY) { y = newY; }
