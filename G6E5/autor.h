#pragma once
#include "vector.h"
#include <iostream>
#include "cancion.h"

class cancion;

class autor{
private:
    Vector<cancion> canciones;
    std::string nombre;
public:
    autor();
    autor(std::string);
    void agregarCancion(cancion);
    void mostrarCanciones();
    const std::string& getNombre() const;
};
