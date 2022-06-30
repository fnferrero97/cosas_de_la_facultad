#ifndef DISCO_H
#define DISCO_H
#include "cancion.h"
#include "vector.h"


class disco{
private:
    Vector<cancion> canciones;
    std::string nombre;
public:
    disco(std::string);
    void agregarCancion(cancion);
    void mostrarCanciones();
    const std::string& getNombre() const;
    const Vector<cancion>& getCanciones() const;
};

#endif // DISCO_H
