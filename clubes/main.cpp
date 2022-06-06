#include "equipo.h"
#include <iostream>
#include "liga.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[]){

    string nombres[] = {"Argentinos Jrs.",
                        "Banfield",
                        "Belgrano",
                        "Boca",
                        "Dep. Espaniol",
                        "Estudiantes (LP)",
                        "Ferro",
                        "Gimnasia (LP)",
                        "Huracan",
                        "Independiente",
                        "Lanus",
                        "Newells",
                        "Platense",
                        "Racing Club",
                        "River",
                        "Rosario Central",
                        "San Lorenzo",
                        "Velez",
                        "Colon",
                        "Gimnasia y Tiro",
                        "San Martin (T)",
                        "Union"};
    Liga ligaArg;

    for(int i = 0; i < 20; i++){
        Equipo equipo(nombres[i],i+1);
        ligaArg.agregarEquipo(equipo);
    }

    //ligaArg.mostrarEquipos();

    ligaArg.generarFechas();

    ligaArg.mostrarFechas();


    return 0;
}

