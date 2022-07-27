#include "portaaviones.h"

char nombreNavio[] = "Portaaviones";
Portaaviones::Portaaviones(int x, int y, char orientacion)
    : Barco(x, y, 5, orientacion, nombreNavio) {}
