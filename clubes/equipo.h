#ifndef EQUIPO_H
#define EQUIPO_H
#include <string>


class Equipo{
private:
    std::string nombre;
    int id;
public:
    Equipo();
    Equipo(std::string, int id);
    std::string &getNombre();
    void setNombre(const std::string &newNombre);
    int getId() const;
    void setId(int newId);
    //Equipo& operator=(Equipo&);
};

#endif // EQUIPO_H
