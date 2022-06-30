#ifndef CUMPLEANIO_H
#define CUMPLEANIO_H
#include <string>

class cumpleanio{
private:
    int dia;
    int mes;
    int anio;
    std::string nombre;
public:
    cumpleanio(int, int, int, std::string);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    std::string getNombre() const;
    ~cumpleanio();
};

#endif // CUMPLEANIO_H
