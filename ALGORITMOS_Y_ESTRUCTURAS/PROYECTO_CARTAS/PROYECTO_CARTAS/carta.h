#ifndef CARTA_H
#define CARTA_H
#include <string>


class carta{
private:
    std::string palo;
    int valor;
public:
    carta();
    ~carta();
    carta(std::string, int);
    const std::string &getPalo() const;
    void setPalo(const std::string &);
    int getValor() const;
    void setValor(int);
};

#endif // CARTA_H
