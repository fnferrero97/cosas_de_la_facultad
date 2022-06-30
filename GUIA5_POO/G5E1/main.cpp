#include <iostream>
#include <complejos.h>

using namespace std;

int main()
{

    Complejo c1(4,5);
    Complejo c2(8,-2);

    cout << c1 << endl;
    cout << c2 << endl;

    Complejo c3 = c1.dividir(c2);

    c3.mostrarFraccion();

    return 0;
}
