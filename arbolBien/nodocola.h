#ifndef NODOCOLA_H
#define NODOCOLA_H

template <class T>
class NodoCola{
private:
    T dato;
    NodoCola* link = nullptr;
public:
    NodoCola(){}

    NodoCola(T dato){
        this->dato = dato;
    }

    const T& getDato() const{
        return this->dato;
    }

    void setDato(const T& dato){
        this->dato = dato;
    }

    NodoCola* getLink() const{
        return this->link;
    }

    void setLink(NodoCola* link){
        this->link = link;
    }
};
#endif // NODOCOLA_H
