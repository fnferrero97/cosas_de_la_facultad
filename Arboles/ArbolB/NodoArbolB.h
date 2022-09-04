#ifndef NODOARBOLB_H
#define NODOARBOLB_H
#include <iostream>

template <class T>
class NodoArbolB {
private:
    T* claves;
    int cantActualClaves;
    int cantTotalClaves;
    NodoArbolB<T>* *hijos;
    bool hoja;
public:
    NodoArbolB<T>();

    NodoArbolB<T>(int cantClaves, bool esHoja){
        this->hoja = esHoja;
        this->cantTotalClaves = cantClaves;

        this->claves = new T[2 * cantTotalClaves - 1];
        this->hijos = new NodoArbolB<T>*[2 * cantTotalClaves];

        this->cantActualClaves = 0;
    }

    void recorrer(){
        int i;
        for (i = 0; i < this->cantActualClaves; i++){
            if (this->hoja == false) this->hijos[i]->recorrer();
            std::cout << " " << this->claves[i];
        }

        if (!this->hoja) this->hijos[i]->recorrer();
    }

    T buscarIndicePorClave(T clave){
        int indice = 0;
        while (indice < this->cantActualClaves && claves[indice] < clave) ++indice;
        return indice;
    }

    void eliminar(T clave){
        int indice = buscarIndicePorClave(clave);

        if (indice < this->cantActualClaves && claves[indice] == clave){
            this->hoja ? eliminarEnHoja(indice) : eliminarEnIntermedio(indice);
        } else {
            if (this->hoja) {
                std::cout << "El valor " << clave << " no existe en el arbol B\n";
                return;
            }

            bool bandera = indice == this->cantActualClaves;

            if (this->hijos[indice]->cantActualClaves < this->cantTotalClaves) this->completar(indice);

            bandera && indice > this->cantActualClaves ? this->hijos[indice - 1]->eliminar(clave) : this->hijos[indice]->eliminar(clave);
        }
        return;
    }

    void eliminarEnHoja(int indice){
        for (int i = indice + 1; i < this->cantActualClaves; ++i){
            this->claves[i - 1] = this->claves[i];
        }
        this->cantActualClaves--;
        return;
    }

    void eliminarEnIntermedio(int indice){
        T claveAuxiliar = this->claves[indice];

        if (this->hijos[indice]->cantActualClaves >= this->cantTotalClaves){
            T anterior = getAnterior(indice);
            this->claves[indice] = anterior;
            this->hijos[indice]->eliminar(anterior);
        } else if  (this->hijos[indice + 1]->cantActualClaves >= this->cantTotalClaves){
            T siguiente = getSiguiente(indice);
            this->claves[indice] = siguiente;
            this->hijos[indice + 1]->eliminar(siguiente);
        } else {
            this->fusionar(indice);
            this->hijos[indice]->eliminar(claveAuxiliar);
        }
        return;
    }

    T getAnterior(int indice){
        NodoArbolB<T>* actual = this->hijos[indice];
        while (!actual->hoja){
            actual = actual->hijos[actual->cantActualClaves];
        }
        return actual->claves[actual->cantActualClaves - 1];
    }

    T getSiguiente(int indice){
        NodoArbolB<T>* actual = this->hijos[indice + 1];
        while (!actual->hoja){
            actual = actual->hijos[0];
        }
        return actual->claves[0];
    }

    void pedirPrestadoAnterior(int indice){
        NodoArbolB<T>* nodo = this->hijos[indice];
        NodoArbolB<T>* hermano = this->hijos[indice - 1];

        for (int i = nodo->cantActualClaves - 1; i >= 0; --i)
            nodo->claves[i + 1] = nodo->claves[i];

        if (!nodo->hoja){
            for (int i = nodo->cantActualClaves; i >= 0; --i)
                nodo->hijos[i + 1] = nodo->hijos[i];
        }

        nodo->claves[0] = this->claves[indice - 1];

        if (!nodo->hoja) nodo->hijos[0] = hermano->hijos[hermano->cantActualClaves];

        this->claves[indice - 1] = hermano->claves[hermano->cantActualClaves - 1];

        nodo->cantActualClaves++;
        hermano->cantActualClaves--;

        return;
    }

    void pedirPrestadoSiguiente(int indice){
        NodoArbolB<T>* nodo = this->hijos[indice];
        NodoArbolB<T>* hermano = this->hijos[indice + 1];

        nodo->claves[nodo->cantActualClaves] = this->claves[indice];

        if (!nodo->hoja)
            nodo->hijos[nodo->cantActualClaves + 1] = hermano->hijos[0];

        this->claves[indice] = hermano->claves[0];

        for (int i = 1; i < hermano->cantActualClaves; ++i){
            hermano->claves[i - 1] = hermano->claves[i];
        }

        if (!hermano->hoja){
            for (int i = 1; i <= hermano->cantActualClaves; ++i){
                hermano->hijos[i - 1] = hermano->hijos[i];
            }
        }

        nodo->cantActualClaves++;
        hermano->cantActualClaves--;
    }

    void completar(int indice){
        if (indice != 0 && this->hijos[indice - 1]->cantActualClaves >= this->cantTotalClaves){
            pedirPrestadoAnterior(indice);
        } else if (indice != this->cantActualClaves && this->hijos[indice + 1]->cantActualClaves >= this->cantTotalClaves){
            pedirPrestadoSiguiente(indice);
        } else {
            indice != this->cantActualClaves ? fusionar(indice) : fusionar(indice - 1);
        }
        return;
    }

    void fusionar(int indice){
        NodoArbolB<T>* nodo = this->hijos[indice];
        NodoArbolB<T>* hermano = this->hijos[indice + 1];

        nodo->claves[this->cantTotalClaves - 1] = this->claves[indice];

        for (int i = 0; i < hermano->cantActualClaves; ++i){
            nodo->claves[i + this->cantTotalClaves] = hermano->claves[i];
        }

        if (!nodo->hoja) {
            for (int i = 0; i <= hermano->cantActualClaves; ++i){
                nodo->hijos[i + this->cantTotalClaves] = hermano->hijos[i];
            }
        }

        for (int i = indice + 1; i < this->cantActualClaves; ++i){
            this->claves[i - 1] = this->claves[i];
        }

        for (int i = indice + 2; i <= this->cantActualClaves; ++i){
            this->hijos[i - 1] = this->hijos[i];
        }

        nodo->cantActualClaves += hermano->cantActualClaves + 1;
        this->cantActualClaves--;

        delete hermano;
        return;
    }

    NodoArbolB<T>* buscarNodo(T clave){
        int i = 0;
        while (i < this->cantActualClaves && clave > claves[i]) i++;

        if (claves[i] == clave) return this;
        if (this->hoja) return NULL;

        return this->hijos[i]->buscarNodo(clave);
    }

    void agregarNoLleno(T dato){
        int i = cantActualClaves - 1;

        if (this->hoja){
            while (i >= 0 && this->claves[i] > dato){
                this->claves[i + 1] = this->claves[i];
                i--;
            }

            this->claves[i + 1] = dato;
            this->cantActualClaves++;
        } else {
            while (i >= 0 && this->claves[i] > dato) i--;

            if (this->hijos[i + 1]->cantActualClaves == 2 * cantTotalClaves - 1){
                partirMitad(i + 1, this->hijos[i + 1]);
                if (this->claves[i + 1] < dato) i++;
            }

            this->hijos[i + 1]->agregarNoLleno(dato);
        }
    }

    void partirMitad(int indice, NodoArbolB<T>* nodo){
        NodoArbolB<T>* nuevoNodo = new NodoArbolB<T>(nodo->cantTotalClaves, nodo->hoja);
        nuevoNodo->cantActualClaves = this->cantTotalClaves - 1;

        for (int i = 0; i < this->cantTotalClaves - 1; i++)
            nuevoNodo->claves[i] = nodo->claves[i + this->cantTotalClaves];

        if (!nodo->hoja){
            for (int i = 0; i < this->cantTotalClaves; i++)
                nuevoNodo->hijos[i] = nodo->hijos[i + this->cantTotalClaves];
        }

        nodo->cantActualClaves = this->cantTotalClaves - 1;

        for (int i = this->cantActualClaves; i >= indice + 1; i--){
            this->hijos[i + 1] = this->hijos[i];
        }

        this->hijos[indice + 1] = nuevoNodo;

        for (int i = this->cantActualClaves - 1; i >= indice; i--){
            this->claves[i + 1] = this->claves[i];
        }

        this->claves[indice] = nodo->claves[this->cantTotalClaves - 1];
        this->cantActualClaves++;
    }

    template <class U>
    friend class ArbolB;
};

#endif // NODOARBOLB_H
