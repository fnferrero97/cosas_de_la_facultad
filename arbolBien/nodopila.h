#ifndef NODOPILA_H
#define NODOPILA_H


template <class T>
class NodoPila{
    private:
        T dato;
        NodoPila* link = nullptr;
    public:
        NodoPila(){}

        NodoPila(T ndato){
            this->dato = ndato;
        }

        const T& getDato() const{
            return dato;
        }

        void setDato(const T& ndato){
            this->dato = ndato;
        }

        NodoPila* getLink() const{
            return this->link;
        }

        void setLink(NodoPila* link){
            this->link = link;
        }
};

#endif // NODOPILA_H
