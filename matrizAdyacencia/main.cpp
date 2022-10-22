#include <iostream>
#include <vector>

bool** crearMatriz(int, int);
int contarArcos(bool**, int);
std::vector<int> leftNodo(bool**, int, int);
std::vector<int> rightNodo(bool**, int, int);
std::vector<int> conjuntoMinimal(bool**, int);
std::vector<int> conjuntoMaximal(bool**, int);
void minimo(bool**, int);
void maximo(bool**, int);


int main(){

    bool** matrizAd = crearMatriz(6, 6);

    matrizAd[1][2] = 1;
    matrizAd[1][3] = 1;
    matrizAd[3][0] = 1;
    matrizAd[3][2] = 1;
    matrizAd[3][3] = 1;
    matrizAd[3][4] = 1;
    matrizAd[4][5] = 1;

    std::cout << "Cantidad de Arcos = " << contarArcos(matrizAd, 6) << "\n";

    for (int i = 0; i < 6; i++){
        std::vector<int> left = leftNodo(matrizAd, 6, i);
        std::vector<int> right = rightNodo(matrizAd, 6, i);

        std::cout << "Left(" << i << ") = ";
        for (auto valor : left){
            std::cout << " " << valor << " - ";
        }
        std::cout << "\n";


        std::cout << "Right(" << i << ") = ";
        for (auto valor : right){
            std::cout << " " << valor << " - ";
        }
        std::cout << "\n";

    }

    std::vector<int> minimal = conjuntoMinimal(matrizAd, 6);
    std::vector<int> maximal = conjuntoMaximal(matrizAd, 6);

    if (!minimal.empty()){
        std::cout << "Conjunto Minimal = ";
        for (auto valor : minimal){
            std::cout << " " << valor << " - ";
        }
        std::cout << "\n";
    } else {
        std::cout << "NO hay conjunto minimal.\n";
    }

    if (!maximal.empty()){
        std::cout << "Conjunto Maximal = ";
        for (auto valor : maximal){
            std::cout << " " << valor << " - ";
        }
        std::cout << "\n";
    } else {
        std::cout << "NO hay conjunto maximal.\n";
    }


    minimo(matrizAd, 6);
    maximo(matrizAd, 6);

    return 0;
}


bool** crearMatriz(int f, int c){
    bool** aux = new bool*[f];
    for(int i = 0; i < f; i++){
        aux[i] = new bool[c];
    }

    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++)
            aux[i][j] =  0;
    }

    return aux;
}

int contarArcos(bool** matriz, int tam){
    int contador = 0;

    for (int i = 0; i < tam * tam; i++){
        if (matriz[i / tam][i % tam]) contador++;
    }
    return contador;
}

std::vector<int> leftNodo(bool** matriz, int tam, int nodo){
    std::vector<int> left;

    for (int i = 0; i < tam; i++){
        if (matriz[i][nodo]) left.push_back(i);
    }

    return left;
}

std::vector<int> rightNodo(bool** matriz, int tam, int nodo){
    std::vector<int> right;

    for (int i = 0; i < tam; i++){
        if (matriz[nodo][i]) right.push_back(i);
    }

    return right;
}

std::vector<int> conjuntoMinimal(bool** matriz, int tam){
    std::vector<int> conjuntoMin;

    for (int i = 0; i < tam; i++){
        if (leftNodo(matriz, tam, i).empty()) conjuntoMin.push_back(i);
    }

    return conjuntoMin;
}

void minimo(bool** matriz, int tam){
    std::vector conjMinimal = conjuntoMinimal(matriz, tam);

    conjMinimal.size() == 1 ? std::cout << "\nEl minimo es: " << conjMinimal[0] << "\n" :
                                           std::cout << "NO hay minimo.\n";
}

std::vector<int> conjuntoMaximal(bool** matriz, int tam){
    std::vector<int> conjuntoMax;

    for (int i = 0; i < tam; i++){
        if (rightNodo(matriz, tam, i).empty()) conjuntoMax.push_back(i);
    }

    return conjuntoMax;
}

void maximo(bool** matriz, int tam){
    std::vector conjMaximal = conjuntoMaximal(matriz, tam);

    conjMaximal.size() == 1 ? std::cout << "\nEl maximo es: " << conjMaximal[0] << "\n" :
                                           std::cout << "NO hay maximo.\n";
}


