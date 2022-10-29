#ifndef EMPRESA_H
#define EMPRESA_H
#include <map>
#include <string>
#include <vector>
#include <time.h>
#include "paquete.h"
#include <fstream>
#include <string.h>
#include <algorithm>

struct Paquetestr{
    char codigo[100];
    char nombre[100];
    int  version;
};

struct Dependenciastr{
    char codigoPaquete[100];
    char codigoPaqueteDependencia[100];
};


class Empresa{
private:
    std::vector<Paquete*> paquetes;
    void escribirDepedenciasPaquete(Paquete*);
    void cargarPaquetes();
    void cargarDependencias();
public:
    Empresa();
    void generarArchivos();
    void cargarArchivos();
    void escribirTxt();
    void dependenciasPaquete(std::string);
    std::vector<Paquete*> cincoMasDependencia();
    std::vector<Paquete*> getSinDependencia();
};

#endif // EMPRESA_H
