#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void mostrar(int** matriz, int n, int m);

int** ejercicio1(int n, int m);
int ejercicio2(int n, int m);
int** ejercicio3(int n, int m, int num);
int** ejercicio4(int** matriz, int n, int m);
int** ejercicio5(int n, int m);
bool ejercicio6(int** matriz, int n, int m, int x, int y, int k,char orientacion);
void ejercicio7(int** matriz, int n, int m, int x, int y);

int main(){

    srand(time(NULL));

    cout << "Ejercicio 1: \n";
    int** p1 = ejercicio1(3, 2);
    mostrar(p1, 3, 2);

    cout << "Ejercicio 2: \n" << ejercicio2(3,2) << "\n\n";

    cout << "Ejercicio 3: \n";
    int** p2 = ejercicio3(2, 4, 40);
    mostrar(p2, 2, 4);

    cout << "Ejercicio 4: \n";
    int** p3 = ejercicio4(p1, 3, 2);
    mostrar(p3, 2, 3);

    cout << "Ejercicio 5: \n";
    int** p4 = ejercicio5(3, 4);
    mostrar(p4, 3, 4);

    cout << "Ejercicio 6: \n";
    if(ejercicio6(p4, 3, 4, 0, 0, 2, 'H'))
        cout << "Verdadero\n\n";
    else
        cout << "Falso\n\n";

    cout << "Ejercicio 7: \n";
    ejercicio7(p4, 3, 4, 0, 3);

    return 0;
}

void mostrar(int** matriz, int n, int m){

    cout << "\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << setw(2) << matriz[i][j] << setw(2) << "  |  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int** ejercicio1(int n, int m){
    int** aux = new int*[n];
    for(int i = 0; i < n; i++){
        aux[i] = new int[m];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            aux[i][j] =  rand() % 50 + 1; //entre 1 y 50 para que no sea tan grande
    }
    return aux;
}

int ejercicio2(int n, int m){
    int** m1 = ejercicio1(n, m);
    int** m2 = ejercicio1(n, m);

    int acum = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            acum += m1[i][j] + m2[i][j];
    }

    delete[] m1;
    delete[] m2;
    return acum;
}

int** ejercicio3(int n, int m, int num){
    int** aux = new int*[n];

    for(int i = 0; i < n; i++){
        aux[i] = new int[m];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            aux[i][j] = num;
    }
    return aux;
}

int** ejercicio4(int** matriz, int n, int m){
    int** aux = new int*[m];
    for(int i = 0; i < m; i++){
        aux[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            aux[j][i] =  matriz[i][j];
    }

    delete[] matriz;
    return aux;
};

int** ejercicio5(int n, int m){
    int num1 = 0;
    int num2 = 1;

    int** aux = new int*[n];

    for (int i = 0; i < n; i++){
        aux[i] = new int[m];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            aux[i][j] = rand() % 2 == 0? num1 : num2;
        }
    }

    return aux;
};

bool ejercicio6(int** matriz, int n, int m, int x, int y, int k, char orientacion){
    if(x > n || y > m) return false;
    if((orientacion == 'H' && x + k > n) || (orientacion == 'V' && y + k > m)) return false;
    if(matriz[x][y] == 1) return false;

    if(orientacion == 'H'){
        for(int i = x; i < k; i++)
            if(matriz[y][i] == 1) return false;
    }

    if(orientacion == 'V'){
        for(int i = y; i < k; i++)
            if(matriz[i][x] == 1) return false;
    }

    return true;
}

void ejercicio7(int** matriz, int n, int m, int x, int y){
    std::cout << "Antes de cambiar\n";
    mostrar(matriz, n, m);

    int num = matriz[x][y] == 0 ? 1 : 0;

    for (int i = 0; i < m; i++){
        if(matriz[x][i] != num){
            matriz[x][i] = num;
        }
    }

    for (int i = 0; i < n ; i++){
        if(matriz[i][y] != num){
            matriz[i][y] = num;
        }
    }

    std::cout << "Despues de cambiar\n";
    mostrar(matriz, n, m);
}




