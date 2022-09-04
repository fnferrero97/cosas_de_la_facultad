#ifndef PERSONA_H
#define PERSONA_H
#include <ostream>



class Persona{
private:
    char* nombre;
    char* apellido;
    long telefono;
public:
    Persona();
    Persona(char*, char*, long);
    char* getNombre() const;
    void setNombre(char *nombre);
    char* getApellido() const;
    void setApellido(char *apellido);
    long getTelefono() const;
    void setTelefono(long telefono);
    friend std::ostream& operator<<(std::ostream&, Persona&);
};

#endif // PERSONA_H
