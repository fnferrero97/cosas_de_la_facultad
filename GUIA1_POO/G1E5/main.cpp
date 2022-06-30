#include <iostream>

using namespace std;

void formalinea(int cant, char simbolo = '#');

int main(int argc, char *argv[])
{

    formalinea(10);
    formalinea(5,'-');
    formalinea(15,'<');


    return 0;
}

void formalinea(int cant, char simbolo){
    for (int i = 0; i < cant; i++){
        cout << simbolo;
    }
    cout << endl << endl;
}
