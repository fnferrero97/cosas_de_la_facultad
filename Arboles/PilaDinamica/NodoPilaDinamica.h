#ifndef NodoPilaDinamica_H
#define NodoPilaDinamica_H


template <class T>
class NodoPilaDinamica{
    private:
        T dato;
        NodoPilaDinamica* link = nullptr;
    public:
        NodoPilaDinamica(){}

        NodoPilaDinamica(T ndato){
            this->dato = ndato;
        }

        const T& getDato() const{
            return dato;
        }

        void setDato(const T& ndato){
            this->dato = ndato;
        }

        NodoPilaDinamica* getLink() const{
            return this->link;
        }

        void setLink(NodoPilaDinamica* link){
            this->link = link;
        }
};

#endif // NodoPilaDinamica_H
