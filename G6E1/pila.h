#ifndef PILA_H
#define PILA_H


class pila{
private:
    int dato;
    int cantElementos;
    pila* link;
public:
    pila() noexcept;
    void alta_pila(int);
    int baja_pila();
    bool pila_vacia();
    int getDato() const;
    void setDato(int newDato);
    void setLink(pila *newLink);
    pila* getLink() const;
};
#endif // PILA_H
