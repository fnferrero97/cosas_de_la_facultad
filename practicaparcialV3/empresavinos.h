#ifndef EMPRESAVINOS_H
#define EMPRESAVINOS_H
#include "vinogeneral.h"
#include <vector>
#include <map>


struct producto{
    int nro;
    char tipo;
    int cantLitros;
    int anioProduccion;
};

class empresaVinos{
private:
    std::vector<vinoGeneral*> vinos;
    std::map<int, std::pair<int, float>> anioLitros;
public:
    empresaVinos();
    void generarArchivo();
    void cantLitrosEnAnio(int);
    void mostrarArchivo();
    void cargarVinos();
    void escribirTxtPorAnio();
    void anioMasLitrosYMontos();
};

#endif // EMPRESAVINOS_H
