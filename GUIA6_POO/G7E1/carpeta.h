#ifndef CARPETA_H
#define CARPETA_H
#include "datas.h"
#include "vector.h"

class carpeta : public datas{
private:
    Vector<datas*> archivos;
public:
    carpeta(std::string);
    float calcularTamanio();
    void agregarArchivo(datas*);
    const std::string& getNombre() const;
    friend std::ostream& operator<<(std::ostream&, carpeta&);
};

#endif // CARPETA_H
