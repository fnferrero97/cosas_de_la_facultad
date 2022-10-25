#ifndef EMPRESA_H
#define EMPRESA_H
#include "empleado.h"
#include <map>
#include <vector>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <string.h>

struct strEmpleado {
    char dni[8];
    char nombre[50];
    char apellido[50    ];
};

struct strTiempo {
    char dni[8];
    int horas;
};


class Empresa {
private:
    std::vector<Empleado> empleados;
    std::map<std::string, int> mapaDNIHORAS;
public:
    Empresa();
    void generarArchivo();
    void cargarMapa();
    void cargarEmpleados();
    void generarTxt();
    std::vector<Empleado> getMayores();
    std::vector<Empleado> getMenores();
};

#endif // EMPRESA_H
