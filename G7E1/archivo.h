#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "datas.h"
#include <string>


class archivo : public datas{
private:
    std::string extension;
    float tamanio;
public:
    archivo();
    archivo(std::string, std::string, float);
    const std::string& getExtension() const;
    float getTamanio() const;
    float calcularTamanio();
    //friend std::ostream& operator<<(std::ostream&, archivo&);
    void mostrarInfo();
};

#endif // ARCHIVO_H
