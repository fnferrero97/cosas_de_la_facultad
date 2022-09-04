#ifndef AGENDA_H
#define AGENDA_H
#include <vector>
#include "persona.h"

class Agenda{
private:
    std::vector<Persona> lista;
public:
    Agenda();
    void agregarPersona(Persona);
    float buscarTelefono(char*, char*);
    const std::vector<Persona>& getLista() const;
};

#endif // AGENDA_H
