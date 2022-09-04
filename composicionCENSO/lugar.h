#ifndef LUGAR_H
#define LUGAR_H

class lugar {
private:
    char* nombre;
public:
    lugar();
    lugar(char*);
    virtual int calcularPoblacion();
};

#endif // LUGAR_H
