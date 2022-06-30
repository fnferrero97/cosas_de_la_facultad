#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    char letra;

    cout << "Ingrese una letra a buscar: ";
    cin >> letra;

    letra = tolower(letra);

    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
        cout << "SI es vocal" << endl;
    } else {
        cout << "NO es vocal" << endl;
    }

    return 0;
}
