#ifndef SISTEMAOPERATIVO_H
#define SISTEMAOPERATIVO_H
#include "carpeta.h"
#include "vector.h"


class sistemaOperativo{
private:
    std::string nombre;
    Vector<carpeta> carpetas;
public:
    sistemaOperativo(std::string);
    float calcularTamanio();
    void agregarCarpeta(carpeta);
    const std::string& getNombre() const;
    friend std::ostream& operator<<(std::ostream&, sistemaOperativo&);
};

#endif // SISTEMAOPERATIVO_H
