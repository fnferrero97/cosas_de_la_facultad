#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {

private:
    long dni;
    string universidad;
public:
    string nombreCompleto;
    char sexo;
    int edad;
    float altura = 0.0;
    float peso = 0.0;

    Persona(string, int, char);

    long getDNI();
    void setDNI(long);
    string getUniversidad();
    void setUniversidad(string);
    void irAClase(int);
    void cumplirAnios();
    void toString();

};



#endif // PERSONA_H
