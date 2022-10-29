#include "empresa.h"


Empresa::Empresa(){}

void Empresa::generarArchivos(){
    srand(time(nullptr));
    Paquetestr paquete;
    Dependenciastr dependencia;
    std::fstream archivoPaquetes("paquetes.dat", std::ios::binary | std::ios::out);
    std::fstream archivoDependencias("dependencias.dat", std::ios::binary | std::ios::out);
    std::vector<char*> codigos = {(char*)"SCL", (char*)"KOT", (char*)"IDEA", (char*)"OJDK", (char*)"IJ", (char*)"JS", (char*)"NPM", (char*)"MSC",(char*) (char*)"NETB", (char*)"BLJ"};
    std::vector<char*> nombres = {(char*)"scala", (char*)"kotlin", (char*)"idea", (char*)"openjdk", (char*)"intelij", (char*)"js", (char*)"npm", (char*)"maicenascript", (char*)"netbeans", (char*)"bluej"};

    for (int i = 0; i < 10; i++){
        strcpy_s(paquete.codigo, codigos[i]);
        strcpy_s(paquete.nombre, nombres[i]);
        paquete.version = rand() % 10 + 1;
        archivoPaquetes.write(reinterpret_cast<char*>(&paquete), sizeof(Paquetestr));
    }

    //    for (int i = 0; i < 7; i++){
    //        strcpy_s(dependencia.codigoPaquete, codigos[rand() % 10]);
    //        strcpy_s(dependencia.codigoPaqueteDependencia, codigos[i+2]);
    //        archivoDependencias.write(reinterpret_cast<char*>(&dependencia), sizeof(Dependenciastr));
    //    }

    strcpy_s(dependencia.codigoPaquete, codigos[0]);
    strcpy_s(dependencia.codigoPaqueteDependencia, codigos[1]);
    archivoDependencias.write(reinterpret_cast<char*>(&dependencia), sizeof(Dependenciastr));

    strcpy_s(dependencia.codigoPaquete, codigos[1]);
    strcpy_s(dependencia.codigoPaqueteDependencia, codigos[3]);
    archivoDependencias.write(reinterpret_cast<char*>(&dependencia), sizeof(Dependenciastr));

    strcpy_s(dependencia.codigoPaquete, codigos[0]);
    strcpy_s(dependencia.codigoPaqueteDependencia, codigos[2]);
    archivoDependencias.write(reinterpret_cast<char*>(&dependencia), sizeof(Dependenciastr));

    strcpy_s(dependencia.codigoPaquete, codigos[5]);
    strcpy_s(dependencia.codigoPaqueteDependencia, codigos[1]);
    archivoDependencias.write(reinterpret_cast<char*>(&dependencia), sizeof(Dependenciastr));

    strcpy_s(dependencia.codigoPaquete, codigos[7]);
    strcpy_s(dependencia.codigoPaqueteDependencia, codigos[0]);
    archivoDependencias.write(reinterpret_cast<char*>(&dependencia), sizeof(Dependenciastr));

    strcpy_s(dependencia.codigoPaquete, codigos[4]);
    strcpy_s(dependencia.codigoPaqueteDependencia, codigos[7]);
    archivoDependencias.write(reinterpret_cast<char*>(&dependencia), sizeof(Dependenciastr));


    archivoPaquetes.close();
    archivoDependencias.close();
}

void Empresa::cargarPaquetes(){
    Paquetestr paquetestr;
    std::fstream archivo("paquetes.dat", std::ios::binary | std::ios::in);

    while (archivo.read(reinterpret_cast<char*>(&paquetestr), sizeof(Paquetestr))){
        std::string codigo(paquetestr.codigo);
        std::string nombre(paquetestr.nombre);
        this->paquetes.emplace_back(new Paquete(codigo, nombre, paquetestr.version));
    }

    archivo.close();
}

void Empresa::cargarArchivos(){
    cargarPaquetes();
    cargarDependencias();
}

void Empresa::cargarDependencias(){
    Dependenciastr dependenciastr;
    std::fstream archivo("dependencias.dat", std::ios::binary | std::ios::in);

    while (archivo.read(reinterpret_cast<char*>(&dependenciastr), sizeof(Dependenciastr))){
        std::string codPaquete(dependenciastr.codigoPaquete);
        std::string codDependencia(dependenciastr.codigoPaqueteDependencia);

        auto paquete = std::find_if(this->paquetes.begin(), this->paquetes.end(), [codPaquete](Paquete* p1){return p1->getCodigo() == codPaquete;});
        auto dependencia = std::find_if(this->paquetes.begin(), this->paquetes.end(), [codDependencia](Paquete* p1){return p1->getCodigo() == codDependencia;});

        (*paquete)->agregarDependencia((*dependencia));
    }
    archivo.close();
}

void Empresa::escribirTxt(){
    for (auto paquete : this->paquetes){
        escribirDepedenciasPaquete(paquete);
    }
}

void Empresa::dependenciasPaquete(std::string codPaquete){
    auto paquete = std::find_if(this->paquetes.begin(), this->paquetes.end(), [codPaquete](Paquete* p1){return p1->getCodigo() == codPaquete;});
    std::cout << *paquete;
}


void Empresa::escribirDepedenciasPaquete(Paquete* paquete){
    std::string path(paquete->getCodigo());
    std::fstream archivo(path + ".txt", std::ios::out | std::ios::trunc);

    archivo << paquete;

    archivo.close();
}


std::vector<Paquete*> Empresa::cincoMasDependencia(){
    std::vector<Paquete*> sinDependencias;
    std::vector<Paquete*> cincoMas;

    std::copy_if(this->paquetes.begin(), this->paquetes.end(), std::back_inserter(sinDependencias), [](Paquete* p1){return p1->noTieneTransitiva();});

    sort(sinDependencias.begin(), sinDependencias.end(), [](Paquete* p1, Paquete* p2){return p1->getDependencias().size() > p2->getDependencias().size();});
    copy(sinDependencias.begin(), sinDependencias.begin() + 5, std::back_inserter(cincoMas));

    return cincoMas;
}

std::vector<Paquete*> Empresa::getSinDependencia(){
    std::vector<Paquete*> sinDepedencia;
    for (auto paquete : this->paquetes){
        if (paquete->noTieneDependencias()){
            sinDepedencia.push_back(paquete);
        }
    }
    return sinDepedencia;
}
