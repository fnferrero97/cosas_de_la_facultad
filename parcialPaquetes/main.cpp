#include <iostream>
#include <empresa.h>

int main(){
    Empresa empresa;

    empresa.generarArchivos();
    empresa.cargarArchivos();
    empresa.escribirTxt();

    empresa.dependenciasPaquete("SCL");

    std::cout << "\n";

    std::vector<Paquete*> sin = empresa.getSinDependencia();
    std::vector<Paquete*> cinco = empresa.cincoMasDependencia();

    for (auto paquete : sin){
        std::cout << paquete << "\n";
    }

    std::cout << "\n";

    for (auto paquete : cinco){
        std::cout << paquete << "\n";
    }

    return 0;
}
