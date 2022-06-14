#include "equipo.h"
#include <iostream>
#include "liga.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[]){

    string nombres[] = {"Platense",
                        "Gimnasia (LP)",
                        "Tigre",
                        "Banfield",
                        "Estudiantes (LP)",
                        "Independiente",
                        "Newells",
                        "River",
                        "Union",
                        "Argentinos",
                        "Boca",
                        "Huracan",
                        "Racing",
                        "Sarmiento (J)",
                        "Colon",
                        "Barracas Central",
                        "Velez",
                        "Def. y Justicia",
                        "Lanus",
                        "San Lorenzo"};
    Liga ligaArg;

    for(int i = 0; i < 20; i++){
        Equipo equipo(nombres[i],i+1);
        ligaArg.agregarEquipo(equipo);
    }

    //ligaArg.mostrarEquipos();
    cout << "\n";

    ligaArg.generarFechas();

    ligaArg.mostrarFechas();


    return 0;
}

