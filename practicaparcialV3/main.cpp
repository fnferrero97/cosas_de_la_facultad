#include <iostream>
#include "empresavinos.h"

int main(){

    empresaVinos empresa;

    empresa.generarArchivo();
    empresa.cargarVinos();
    empresa.mostrarArchivo();

    empresa.escribirTxtPorAnio();
    empresa.anioMasLitrosYMontos();

    return 0;
}
