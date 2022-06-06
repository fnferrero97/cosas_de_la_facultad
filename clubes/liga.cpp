#include "liga.h"

Liga::Liga(){}

void Liga::agregarEquipo(Equipo equipo){
    this->equipos.push_back(equipo);
    this->cantEquipos++;
}

void Liga::agregarFecha(Fecha fecha){
    this->fechas.push_back(fecha);
}

void Liga::generarFechas(){

    if(cantEquipos % 2 != 0){
        this->equipos.emplace_back("LIBRE", 99);
        this->cantEquipos++;
    }

    this->cantFechas = (this->getCantEquipos() - 1) * 2;
    this->cantPartidos = ((this->getCantEquipos() / 2) * 2) - 1;

    for (int i = 0; i < this->cantFechas; i++){
        Fecha fecha(i+1);

        for (int j = 0; j <= this->cantPartidos; j+=2){
            if (i%2 == 0){
                Partido partido(this->equipos[j], this->equipos[j+1]);
                fecha.agregarPartido(partido);
            } else {
                Partido partido(this->equipos[j+1], this->equipos[j]);
                fecha.agregarPartido(partido);
            }

        }

        for (int k = this->getCantEquipos()-1; k > 1; k--){
            Equipo aux(this->equipos[k - 1].getNombre(), this->equipos[k -1].getId());
            this->equipos[k-1] = this->equipos[k];
            this->equipos[k] = aux;
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
        std::cout << "Fecha nro: " << this->fechas[i].getNroFecha() << "\n";
        std::cout << "#######################\n";
        this->fechas[i].mostrarFecha();
        std::cout << "#######################\n\n";
    }
}


int Liga::getCantEquipos() const{
    return cantEquipos;
}


