#ifndef CATALOGO_H
#define CATALOGO_H
#include "vector.h"
#include "disco.h"


class catalogo {
private:
    std::string nombre;
    Vector<disco> articulos;
public:
    catalogo(std::string);
    void agregarDisco(disco);
    void mostrarCatalogo();
    const std::string &getNombre() const;
};

#endif // CATALOGO_H
