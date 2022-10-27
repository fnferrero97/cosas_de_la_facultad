#include "correlativo.h"
#include "empresa.h"
#include "simple.h"

#include <Compuesto.h>
#include <iostream>

//Empresa -> Cursos -> buscar5MenosHoras() - Tema que aparece mas.

//Curso -> Padre -> codigo #N - horasAsignadas - nombre - temaRelacionado - virutal calcularHoras = 0

//Simple -> IGUAL AL PAPA, calcula las horas normal.
//Correlatividad -> codigoCorrelativo, calcula la de todas sus cursos correlativos
//Compuesto -> vector de simples, calcula las horas sumando todas las que estan dentro.


int main() {

    Empresa empresa((char*)"FCyT");

    Curso* curso1 = new Simple((char*)"AAA10", (char*)"Matematica 1", (char*)"FUNCIONES", 150.f);
    empresa.agregarCurso(curso1);

    Curso* curso2 = new Simple((char*)"AAB20", (char*)"Matematica 2", (char*)"DERIVADA", 100.f);
    empresa.agregarCurso(curso2);

    Simple curso3((char*)"AAAxx", (char*)"Artesania", (char*)"CERAMICA", 20.f);
    Simple curso4((char*)"AAAxx", (char*)"Cortar Pasto", (char*)"MAQUINA", 35.f);

    Correlativo curso6((char*)"AAA30", (char*)"Matematica 3", (char*)"FASO", 150.f);
    curso6.agregarCorrelativas(curso1);
    curso6.agregarCorrelativas(curso2);
    Curso* curso7 = &curso6;
    empresa.agregarCurso(curso7);


    Compuesto curso10((char*)"AAA00", (char*)"MANUALIDADES", (char*)"DE TODO UN POCO");
    curso10.agregarCurso(curso3);
    curso10.agregarCurso(curso4);
    Curso* curso11 = &curso10;
    empresa.agregarCurso(curso11);

    Curso* curso12 = new Simple((char*)"AAA40", (char*)"DISCRETA 1", (char*)"NOS COJIERON", 300.f);
    empresa.agregarCurso(curso12);

    Curso* curso13 = new Simple((char*)"AAB50", (char*)"DISCRETA 2", (char*)"DERIVADA DE LA PENDIENTE", 400.f);
    empresa.agregarCurso(curso13);

    empresa.calcularHorasCursos();
    empresa.obtener5MenosHoras();



    return 0;
}
