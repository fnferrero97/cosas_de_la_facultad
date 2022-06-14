#include "liga.h"
#include <iomanip>

Liga::Liga(){}

void Liga::agregarEquipo(Equipo equipo){
    this->equipos.push_back(equipo);
    this->cantEquipos++;
}

void Liga::agregarFecha(Fecha fecha){
    this->fechas.push_back(fecha);
}

void Liga::generarFechas(){
    int cantidadEquipos;
    int local;
    int visitante;

    if(this->getCantEquipos() % 2 != 0){
        this->equipos.emplace_back("LIBRE", 99);
        cantidadEquipos = this->cantEquipos;
        this->cantFechas = this->getCantEquipos() * 2;
    } else {
        this->cantFechas = (this->getCantEquipos() - 1) * 2;
        cantidadEquipos = this->cantEquipos-1;
    }

    this->cantPartidos = this->getCantEquipos() / 2;

    for (int i = 0; i < this->cantFechas; i++){
        Fecha fecha(i+1);
        for (int j = 0; j < this->cantPartidos; j++){
            Partido partido;
            local = (i + j) % cantidadEquipos;
            visitante = (i - j + cantidadEquipos) % cantidadEquipos;

            if(j == 0) visitante = cantidadEquipos;

            i%2 == 0 ? partido.setEquipos(this->equipos[local], this->equipos[visitante]) :
                       partido.setEquipos(this->equipos[visitante], this->equipos[local]);

            fecha.agregarPartido(partido);
            }
        this->fechas.push_back(fecha);
    }
}

void Liga::mostrarEquipos(){
    for (size_t i = 0; i < this->equipos.size(); i++){
        std::cout << this->equipos[i].getNombre() << "\n";
    }
}

void Liga::mostrarFechas(){
    for (size_t i = 0; i < this->fechas.size(); i++){
        std::cout << "                         Fecha nro: " << this->fechas[i].getNroFecha() << "\n";
        std::cout << "#####################################################################\n";
        this->fechas[i].mostrarFecha();
        std::cout << "#####################################################################\n\n";
    }
}


int Liga::getCantEquipos() const{
    return cantEquipos;
}


