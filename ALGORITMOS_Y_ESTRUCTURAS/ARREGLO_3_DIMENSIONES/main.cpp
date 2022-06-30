#include <iostream>
#include <time.h>

using namespace std;


int main(int argc, char *argv[])
{
    int ganancias[7] = {0};
    int organizaciones[35][12][7];

    srand(time(NULL));

    for (int i = 0; i < 35; i++){
        for (int j = 0; j < 12; j++){
            for (int k = 0; k < 7; k++){
                organizaciones[i][j][k] = rand()& 51+1;
                ganancias[k] += organizaciones[i][j][k];
            }
        }
    }


    for (int i = 0; i < 7; i++){
        cout << "Las ganancias de la sucursal " << i+1 << " son: " << ganancias[i] << endl;
    }

    return 0;
}

