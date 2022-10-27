#ifndef CURSO_H
#define CURSO_H
#include <string.h>
#include <iostream>

struct struct_curso {
    char codigo[5];
    char nombre[15];
    char temaRelacionado[20];
    float cantHorasAsignadas;
};

class Curso {
private:
    char* codigoAN;
    char* nombre;
    char* temaRelacionado;
    float cantHorasAsignadas;

public:
    Curso();
    Curso(char*, char*, char*, float = 0);
    float virtual calcularHoras() = 0;
    char *getCodigoAN() const;
    void setCodigoAN(char *codigoAN);
    char *getNombre() const;
    void setNombre(char *nombre);
    char *getTemaRelacionado() const;
    void setTemaRelacionado(char *temaRelacionado);
    float getCantHorasAsignadas() const;
    void setCantHorasAsignadas(float cantHorasAsignadas);
    friend std::ostream& operator<<(std::ostream&, Curso&);
};

#endif // CURSO_H
