#include "empresavinos.h"
#include <fstream>
#include <time.h>
#include <vector>
#include <iostream>
#include "vinoespecial.h"
#include "vinogeneral.h"
#include "vinopremium.h"
#include "vinomesa.h"
#include <algorithm>


bool comparaAnio(vinoGeneral* v1, vinoGeneral* v2){
    return (v1->getAnioProduccion() > v2->getAnioProduccion()) || ((v1->getAnioProduccion() == v2->getAnioProduccion()) && (v1->getTipo() > v2->getTipo()));
}

empresaVinos::empresaVinos(){}

void empresaVinos::generarArchivo(){
    std::vector<char> tipos(3);
    tipos[0] = 'M';
    tipos[1] = 'P';
    tipos[2] = 'E';
    srand(time(nullptr));

    producto prod;
    std::fstream archivo("vinos.bin", std::ios::binary | std::ios::out);

    for (int i = 0; i < 10; i++){
        prod.nro = rand() % 150;
        prod.tipo = tipos[rand() % 3];
        prod.cantLitros = rand() % 3 + 1;
        prod.anioProduccion = rand() % (2025 - 2015 + 1) + 2015;
        archivo.write((char*)&prod, sizeof(producto));
    }

    archivo.close();
}

void empresaVinos::cantLitrosEnAnio(int anio){
    std::fstream archivo("litrosPorAnio.txt", std::ios::in | std::ios::app);
    if (archivo.is_open()){
        float litros = 0;
        float montos = 0;
        for (auto vino : vinos){
            if (vino->sePuedeVender(anio)){
                litros += vino->getLitros();
                montos += vino->calcularPrecio();
            }
        }
        this->anioLitros[anio] = {litros, montos};
        archivo << "AÑO..." << anio << " LITROS..." << litros << " MONTO..." << montos << "\n";
    } else {
        std::cout << "NO ME LA CONTES!\n";
    }
    archivo.close();
}

void empresaVinos::mostrarArchivo(){
    producto prod;
    std::fstream archivo("vinos.bin", std::ios::binary | std::ios::in);

    while (archivo.read((char*)&prod, sizeof(producto))){
        std::cout << "nro: " << prod.nro << " - tipo: " << prod.tipo << " - cantLitros: " << prod.cantLitros << " - anioProduccion: " << prod.anioProduccion << "\n";
    }

    archivo.close();
}

void empresaVinos::escribirTxtPorAnio(){
    for (int i = 2020; i < 2029; i++){
        cantLitrosEnAnio(i);
    }
}

void empresaVinos::cargarVinos(){
    producto prod;
    std::fstream archivo("vinos.bin", std::ios::binary | std::ios::in);

    if (archivo.is_open()){
        while (archivo.read((char*)&prod, sizeof(producto))){
            switch (prod.tipo){
                case 'M':{
                    this->vinos.emplace_back(new vinoMesa(prod.nro, prod.cantLitros, prod.tipo, prod.anioProduccion));
                    break;
                }
                case 'P':{
                    this->vinos.emplace_back(new vinoPremium(prod.nro, prod.cantLitros, prod.tipo, prod.anioProduccion));
                    break;
                }
                case 'E':{
                    this->vinos.emplace_back(new vinoEspecial(prod.nro, prod.cantLitros, prod.tipo, prod.anioProduccion));
                    break;
                }
            }
        }
    } else {
        std::cout << "NO ME LA CONTES!";
    }

    archivo.close();
}

void empresaVinos::anioMasLitrosYMontos(){
    sort(this->vinos.begin(), this->vinos.end(), comparaAnio);

    int offset;
    int mejorAnio = this->vinos[0]->getAnioProduccion();

    switch(this->vinos[0]->getTipo()){
        case 1: {
            offset = 1;
            break;
        }
        case 2:{
            offset = 2;
            break;
        }
        case 3:{
            offset = 3;
            break;
        }
    }
    std::cout << "El anio que se puede vender mas vino es: " << mejorAnio + offset << ".\n";
    std::cout << "El anio que se puede obtener el mayor monto es: " << mejorAnio + offset << ".\n";
}



