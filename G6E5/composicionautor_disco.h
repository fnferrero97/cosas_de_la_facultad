#ifndef COMPOSICIONAUTOR_DISCO_H
#define COMPOSICIONAUTOR_DISCO_H
#include "cancion.h"
#include "vector.h"
#include <iostream>


class composicionAutor_Disco{
private:
    Vector<cancion> canciones;
    std::string nombre;
public:
    composicionAutor_Disco(std::string);
    void agregarCancion(cancion);
    void mostrarCanciones();
};

#endif // COMPOSICIONAUTOR_DISCO_H
