#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>


class Empleado{
private:
    std::string dni;
    std::string nombre;
    std::string apellido;
    int horasTrabajadas;
public:
    Empleado();
    Empleado(std::string, std::string, std::string, int);
    int getHorasTrabajadas() const;
    void setHorasTrabajadas(int horasTrabajadas);
    const std::string &getDni() const;
    void setDni(const std::string &dni);
    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);
    const std::string &getApellido() const;
    void setApellido(const std::string &apellido);
};

#endif // EMPLEADO_H
