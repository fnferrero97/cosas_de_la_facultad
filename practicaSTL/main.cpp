#include <iostream>
#include <algorithm>
#include <map>
#include <time.h>
#include <vector>
#include "persona.h"
#include <string>
#include "agenda.h"

void mostrarSeparador(int cant, char caracter = '#'){
    std::cout << "\n";
    for (int i = 0; i < cant; i++) std::cout << caracter;
    std::cout << "\n";
}


int main(){
    srand(time(NULL));

    std::string texto = "puta madre pa";
    std::string palabraActual = "";

    std::map<std::string, int> cantPalabras;


    for(size_t i = 0; i <= texto.length(); i++){
        if (texto[i] != ' ' && i < texto.length()){
            palabraActual += texto[i];
        } else if (cantPalabras.count(palabraActual) == 0){
            cantPalabras[palabraActual] = 1;
            palabraActual = "";
        } else {
            cantPalabras[palabraActual]++;
            palabraActual = "";
        }
    }
        for (auto it = cantPalabras.begin(); it != cantPalabras.end(); ++it){
            std::cout << it->first  << ':' << it->second << "\n";
        }


//    std::vector<char*> nombres = {"Facundo",
//                                  "Ferrrero",
//                                  "Francisco",
//                                  "Ramirez",
//                                  "Amaya",
//                                  "Ortuno",
//                                  "Portillo",
//                                  "Chita",
//                                  "Corral",
//                                  "Gimenez",
//                                  "Lucia",
//                                  "Perlita",
//                                  "Seco",
//                                  "Pineiro"
//                                 };
//    Agenda agenda;

//    for (int i = 0; i < 10; i++){
//        Persona p(nombres[i*rand()%nombres.size()], nombres[(i+1)*rand()%nombres.size()], (i*i)*i+1042);
//        agenda.agregarPersona(p);
//    }

//    std::cout << "TEL: " << agenda.buscarTelefono((char*)"Facundo", (char*)"Ferrero") << "\n";

//    mostrarSeparador(10, '-');

//    for (Persona p : agenda.getLista()){
//        std::cout << p;
//    }

//    std::vector<int> numeros(200);
//    for(int i = 0; i < 200; i++) numeros[i] = rand() % 500 + 1;

//    for(int n : numeros) std::cout << n << " - ";
//    mostrarSeparador(25);

//    std::cout << "Ordenados desde el 10 hasta el 150 en forma descendiente\n";
//    mostrarSeparador(25);

//    //caso 1
//    //sort(numeros.begin() + 5, numeros.end() - 50,[](int a, int b){return a > b;});

//    //caso 2
//    sort(numeros.rbegin()+50, numeros.rend()-10);

//    //caso 3
//    //sort(numeros.begin()+10, numeros.end()-50);
//    //reverse(numeros.begin()+10, numeros.end()-50)

//    for(auto it = numeros.begin(); it != numeros.end(); ++it){
//        std::cout << *it << " - ";
//    }

    return 0;

}
