#ifndef DATAS_H
#define DATAS_H
#include <string>


class datas{
private:
    std::string nombre;
public:
    datas(std::string);
    const std::string& getNombre() const;
    float virtual calcularTamanio() = 0;
};

#endif // DATAS_H
