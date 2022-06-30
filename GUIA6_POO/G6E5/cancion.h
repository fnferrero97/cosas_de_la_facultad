#pragma once
#include <string>
#include "autor.h"

class autor;

class cancion{
private:
    std::string nombre;
    autor* autor = NULL;
public:
    cancion();
    cancion(std::string nombre, class autor*);
    const std::string& getNombre() const;
    void setNombre(const std::string& newNombre);
    const std::string &getAutor() const;
    void setAutor(class autor* newAutor);
};

