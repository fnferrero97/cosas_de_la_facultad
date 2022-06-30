#include <iostream>
#include "cancion.h"
#include "catalogo.h"
#include "disco.h"
#include "autor.h"
#include "vector.h"

// Deseamos diseñar un software que mantenga los catálogos de la música, una canción tiene
// un autor que pudo componer varias canciones. A la vez un disco esta compuesto por un
// conjunto de canciones que no necesariamente son de un solo autor.

// cancion - nombre y autor
// composicion
// autor - nombre y canciones[]
// disco - nombre y canciones[] diferentes autores
// catalogo - discos[]


using namespace std;

int main(int argc, char *argv[]){


    autor* autor1 = new autor("wasa");
    autor* autor2 = new autor("pablo");
    autor* autor3 = new autor("colo");
    autor* autor4 = new autor("feli");

    cancion cancion1("Hola", autor1);
    cancion cancion2("Chau", autor2);
    cancion cancion3("Volatil", autor3);
    cancion cancion4("Demasiano", autor4);

    disco disco1("ALTA CUMBIA PA");
    disco disco2("ELECTRO CHILL");
    catalogo catalogo1("TOP 10 ARG");

    autor1->agregarCancion(cancion1);
    autor2->agregarCancion(cancion2);
    autor3->agregarCancion(cancion3);
    autor4->agregarCancion(cancion4);

    autor1->mostrarCanciones();
    autor2->mostrarCanciones();
    autor3->mostrarCanciones();
    autor4->mostrarCanciones();

    cout << "-------------\n";

    disco1.agregarCancion(cancion1);
    disco1.agregarCancion(cancion2);
    disco2.agregarCancion(cancion3);
    disco2.agregarCancion(cancion4);

    disco1.mostrarCanciones();
    disco2.mostrarCanciones();

    cout << "-------------\n";

    catalogo1.agregarDisco(disco1);
    catalogo1.agregarDisco(disco2);
    catalogo1.mostrarCatalogo();

    cout << "-------------\n";


    return 0;
}
