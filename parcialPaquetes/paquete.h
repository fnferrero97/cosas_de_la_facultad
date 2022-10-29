#ifndef PAQUETE_H
#define PAQUETE_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>


class Paquete {
private:
    std::string codigo;
    std::string nombre;
    int version;
    std::vector<Paquete*> dependencias;
public:
    Paquete();
    Paquete(std::string, std::string, int);
    void agregarDependencia(Paquete*);
    const std::string& getCodigo() const;
    void setCodigo(const std::string &codigo);
    const std::string& getNombre() const;
    void setNombre(const std::string &nombre);
    int getVersion() const;
    void setVersion(int version);
    const std::vector<Paquete*> &getDependencias() const;
    bool noTieneDependencias();
    friend std::ostream& operator<<(std::ostream&, Paquete*&);
};

#endif // PAQUETE_H
