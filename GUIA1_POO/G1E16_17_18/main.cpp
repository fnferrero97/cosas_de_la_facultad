#include <iostream>
#include <string>

using namespace std;

bool esFechaValida(string fecha);
bool esBisiesto(int anio);
int calculaDias(string fecha1, string fecha2);

int main(int argc, char *argv[])
{

    string fecha1, fecha2;

    cout << "Ingrese la primer fecha en formato dd/mm/aaaa: ";
    getline(cin, fecha1);

    cout << "Ingrese la segunda fecha en formato dd/mm/aaaa: ";
    getline(cin, fecha2);


    if(esFechaValida(fecha1) && esFechaValida(fecha2)){
        cout << "La diferencia es de: " << calculaDias(fecha1, fecha2) << " dias." << endl;
    } else {
        cout << "La diferencia es de: 0 ya que las fechas NO son validas." << endl;
    }

    return 0;
}

int calculaDias(string fecha1, string fecha2){

    int dia1 = stoi(fecha1.substr(0,2));
    int mes1 = stoi(fecha1.substr(3,2));
    int anio1 = stoi(fecha1.substr(6,4));

    int dia2 = stoi(fecha2.substr(0,2));
    int mes2 = stoi(fecha2.substr(3,2));
    int anio2 = stoi(fecha2.substr(6,4));

    return abs((dia1-dia2) + ((mes1-mes2) * 30.4375) + ((anio1-anio2) * 365.25));

}

bool esBisiesto(int anio){

    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;

}

bool esFechaValida(string fecha){

    int dia = stoi(fecha.substr(0,2));
    int mes = stoi(fecha.substr(3,2));
    int anio = stoi(fecha.substr(6,4));

    if (anio > 1581){
        switch (mes){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 11:
                   if (dia > 0 && dia <= 31){
                       return true;
                   } else {
                       return false;
                   }
                   break;
            case 2:
                  if (esBisiesto(anio)){
                     if (dia > 0 && dia <= 29){
                        return true;
                     }
                   } else {
                         if (dia > 0 && dia <= 28){
                            return true;
                         }
                         else {
                            return false;
                        }
                   }
                   break;
            case 4:
            case 6:
            case 9:
            case 12:
                   if (dia > 0 && dia <= 30){
                       return true;
                   } else {
                       return false;
                   }
                   break;
            default: return false;
        }
    } else {
        return false;
    }
}
