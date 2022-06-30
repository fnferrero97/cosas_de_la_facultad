#include "archivo.h"
#include "sistemaoperativo.h"
#include <iostream>
#include "datas.h"
using namespace std;

int main(int argc, char *argv[]){

    sistemaOperativo os("Windows 225");
    carpeta carpeta1("Multimedia");
    carpeta* carpeta2 = new carpeta("Anashe");

    //datas* carpeta2 = new class carpeta("Anashe");

    for (int i = 0; i < 11; i++){
        datas* archivo = new class archivo("archivo" + to_string(i), ".png", i*0.15f+i);
        carpeta2->agregarArchivo(archivo);
    }


    archivo* archivo3 = new archivo("peronismo", ".bat", 100.f);
    carpeta1.agregarArchivo(carpeta2);
    carpeta1.agregarArchivo(archivo3);
    cout << carpeta1.calcularTamanio() << "\n";
    os.agregarCarpeta(carpeta1);
    cout << os.calcularTamanio() << "\n";

    //cout << carpeta1 << "\n";
    //cout << os << "\n";

    return 0;
}
