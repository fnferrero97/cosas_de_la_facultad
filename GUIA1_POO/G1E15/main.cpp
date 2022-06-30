#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

void muestraMenu();
void calculaDoble(int dato);
void determinaPar(int dato);
void determinaPrimo(int dato, int chequa);

int main(int argc, char *argv[]) {

    char opcion;
    int dato;

    do {

        muestraMenu();

        cin >> opcion;

        opcion = toupper(opcion);

        switch(opcion){

        case 'A':
        cout << "Ingrese el dato: ";
        cin >> dato;
        calculaDoble(dato);
        cin.ignore();
        break;

        case 'B':
        cout << "Ingrese el dato: ";
        cin >> dato;
        determinaPar(dato);
        cin.ignore();
        break;

        case 'C':
        cout << "Ingrese el dato: ";
        cin >> dato;
        determinaPrimo(dato,2);
        cin.ignore();
        break;

        case 'D' :
        cout << "----------------------" << endl;
        cout << "Gracias por usar el programa!" << endl;
        cout << "----------------------" << endl;
        break;

        default:
        cout << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "   OPCION NO VALIDA  " << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << endl;
        }

    }

    while(opcion != 'D');

    return 0;
}

void muestraMenu(){
    cout << "CALCULOS" << endl;
    cout << "----------------------" << endl;
    cout << "A- Calcular el doble del dato." << endl;
    cout <<	"B- Determinar si es par." << endl;
    cout <<	"C- Determinar si es primo." << endl;
    cout <<	"D- Salir." << endl;
    cout << "Elija una Opcion (A-D): ";
}

void calculaDoble(int dato){
    cout << "----------------------" << endl;
    cout << "El doble del dato " << dato << " es " << (dato*2) << endl;
    cout << "----------------------" << endl;
}

void determinaPar(int dato){
    if (dato % 2 == 0){
        cout << "----------------------" << endl;
        cout << "El dato " << dato << " es par" << endl;
        cout << "----------------------" << endl;
    } else {
        cout << "----------------------" << endl;
        cout << "El dato " << dato << " no es par" << endl;
        cout << "----------------------" << endl;
    }
}

void determinaPrimo(int dato, int chequea){
        if(dato == 1 || dato == 2){
            cout << "----------------------" << endl;
            cout << "SI es primo" << endl;
            cout << "----------------------" << endl;
        }
        else if(dato % chequea == 0 && dato != chequea){
            cout << "----------------------" << endl;
            cout << "NO es primo" << endl;
            cout << "----------------------" << endl;
        }
        else if(dato == chequea){
            cout << "----------------------" << endl;
            cout << "SI es primo" << endl;
            cout << "----------------------" << endl;
        }
        else {
            return determinaPrimo(dato, chequea+1);
            }
    }
