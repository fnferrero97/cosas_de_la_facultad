#include "empresa.h"

Empresa::Empresa(){}

Empresa::Empresa(char* nombre){
    this->nombre = nombre;
}

void Empresa::calcularHorasCursos(){
    for (Curso* curso : this->cursos){
        this->horasPorCurso[curso->getCodigoAN()] = curso->calcularHoras();
    }
}

void Empresa::agregarCurso(Curso* curso){
    this->cursos.push_back(curso);
}

bool comparaHoras(Curso* curso1, Curso* curso2){
    return curso1->calcularHoras() < curso2->calcularHoras();
}

void Empresa::obtener5MenosHoras(){
    sort(this->cursos.begin(), this->cursos.end(), comparaHoras);

    for (int i = 0; i < 5; i++){
        auto it = this->horasPorCurso.find(this->cursos[i]->getCodigoAN());
        std::cout << *this->cursos[i] << " - Horas asignadas: " << it->second << "\n";
    }
}
