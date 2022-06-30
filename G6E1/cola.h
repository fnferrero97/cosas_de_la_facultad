#ifndef COLA_H
#define COLA_H


class cola{
private:
    int dato;
    int cantElementos;
    cola* frente;
    cola* fondo;
    cola* link;
public:
    cola();
    void alta_cola(int);
    int baja_cola();
    bool cola_vacia();
    int getDato() const;
    void setDato(int newDato);
    cola* getLink() const;
    void setLink(cola* newLink);
};

#endif // COLA_H
