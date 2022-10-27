#ifndef EMPRESA_H
#define EMPRESA_H
#include "curso.h"
#include <map>
#include <vector>
#include <algorithm>

class Empresa {
private:
    char* nombre;
    std::vector<Curso*> cursos;
    std::map<char*, float> horasPorCurso;
public:
    Empresa();
    Empresa(char*);
    void calcularHorasCursos();
    void agregarCurso(Curso*);
    void obtener5MenosHoras();
};

#endif // EMPRESA_H
