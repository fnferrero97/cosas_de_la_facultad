#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include <iostream>


class Empleado{
private:
    std::string nombre;
    std::string apellido;
    long cuil;
    float sueldoFijo;
public:
    Empleado();
    Empleado(std::string, std::string, long, float);
    float virtual calcularSueldo() = 0;
    void virtual getInfo();
    const std::string &getNombre() const;
    void setNombre(const std::string&);
    const std::string &getApellido() const;
    void setApellido(const std::string&);
    float getSueldoFijo() const;
    void setSueldoFijo(float);
    long getCuil() const;
    void setCuil(long);
};

#endif // EMPLEADO_H
