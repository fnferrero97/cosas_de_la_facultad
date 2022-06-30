#include "mazo.h"
#include <cstddef>

mazo::mazo(){

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 12; j++){
            carta carta(this->palos[i], this->valores[j]);
            this->cartas.agregarAtras(carta);
        }
    }

    for (int i = 0; i < 2; i++){
        carta carta("COMODIN", 99);
        this->cartas.agregarAtras(carta);
    }

}

void mazo::intercambiar(int valor1, int valor2) {

   ListaCircular<carta>* pos1 = this->cartas.getLink();
   ListaCircular<carta>* pos2 = this->cartas.getLink();

   for(int i = 1; i < valor1; i++) {
     pos1 = pos1->getLink();
   }

   for(int i = 1; i < valor2; i++) {
     pos2 = pos2->getLink();
   }

   carta valoraux = pos1->getDato();
   pos1->setDato(pos2->getDato());
   pos2->setDato(valoraux);

}


void mazo::mezclar(int cantidad){

    srand(time(NULL));
    for(int i = 0; i < cantidad; i++){
        int valor1 = rand() % 50 + 1;
        int valor2 = rand() % 50 + 1;

        if (valor1 != valor2){
            this->intercambiar(valor1, valor2);
        }
    }
}

void mazo::repartir(){
    for (int i = 0; i<6; i++){
        this->cartas.eliminarAtras();
    }
}

//void mazo::mostrar(){
//    std::cout << "El mazo contiene 50 cartas en este orden: \n";

//    ListaCircular<carta>* aux = this->cartas.getLink();

//    if(this->cartas.getLink() == NULL){
//        std::cout << "El mazo esta vacio \n";
//    } else {
//        do {
//            if(aux->getDato().getPalo() == "COMODIN"){
//               std::cout << aux->getDato().getPalo() << "\n";
//            } else {
//                std::cout << aux->getDato().getValor() << " de " << aux->getDato().getPalo() << "\n";
//            }
//            aux = aux->getLink();
//        } while(aux->getLink() != this->cartas.getLink());
//    }

//    if(aux->getDato().getPalo() == "COMODIN"){
//        std::cout << aux->getDato().getPalo() << "\n";
//    }  else {
//        std::cout << aux->getDato().getValor() << " de " << aux->getDato().getPalo() << "\n";
//    }
//}

std::ostream& operator<<(std::ostream& os, mazo& mazo){
    os << "El mazo contiene 50 cartas en este orden: \n";

    ListaCircular<carta>* aux = mazo.cartas.getLink();

    if(mazo.cartas.getLink() == NULL){
        std::cout << "El mazo esta vacio \n";
    } else {
        do {
            if(aux->getDato().getPalo() == "COMODIN"){
               std::cout << aux->getDato().getPalo() << "\n";
            } else {
                std::cout << aux->getDato().getValor() << " de " << aux->getDato().getPalo() << "\n";
            }
            aux = aux->getLink();
        } while(aux->getLink() != mazo.cartas.getLink());
    }

    if(aux != mazo.cartas.getLink()){
        if(aux->getDato().getPalo() == "COMODIN"){
            os << aux->getDato().getPalo() << "\n";
        }  else {
            os << aux->getDato().getValor() << " de " << aux->getDato().getPalo() << "\n";
        }
    }
    return os;
}
