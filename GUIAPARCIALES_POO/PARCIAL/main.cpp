#include <iostream>

using namespace std;

int enigma(int num);

int main(int argc, char *argv[])
{
    cout << enigma(8) << endl << endl;
    cout << enigma(10) << endl << endl;
    cout << enigma(13) << endl << endl;

    return 0;
}

int enigma(int num){
    if(num < 2){
        return num;
    } else {
        return num%2 + (10 * enigma(num/2));
    }
}
