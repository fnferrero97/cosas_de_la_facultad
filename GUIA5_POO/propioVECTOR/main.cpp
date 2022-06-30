#include <iostream>
#include <string>
#include "vector.h"
#include "cumpleanio.h"
#include "agenda.h"

template <typename T>
void mostrarVector(const Vector<T> &vector){

    for (int i = 0; i < vector.getTamanio(); i++){
        std::cout <<  vector[i] << std::endl;
    }

    std::cout << "-------------" << std::endl;
}

int main(int argc, char *argv[]){

    agenda agenda;
    cumpleanio c1(26, 3, 1997, "Facu");
    cumpleanio c2(18, 3, 1997, "Pablo");
    cumpleanio c3(12, 7, 2001, "Joaco");
    cumpleanio c4(26, 5, 1997, "Franco");
    cumpleanio c5(15, 4, 2000, "Tomi");

    agenda.agregarCumpleanio(c1);
    agenda.agregarCumpleanio(c2);
    agenda.agregarCumpleanio(c3);
    agenda.agregarCumpleanio(c4);
    agenda.agregarCumpleanio(c5);

    agenda.mostrarCumpleanios();

    std::cout << "---" << std::endl;
    agenda.mostrarCumpleanios(agenda.getPorDia(26));

    std::cout << "---" << std::endl;
    agenda.mostrarCumpleanios(agenda.getPorMes(5));

    return 0;
}
