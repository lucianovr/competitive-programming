#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int ddd;

    cin >> ddd;

    if (ddd == 61)
        cout << "Brasilia\n";
    else if (ddd == 71)
        cout << "Salvador\n";
    else if (ddd == 11)
        cout << "Sao Paulo\n";
    else if (ddd == 21)
        cout << "Rio de Janeiro\n";
    else if (ddd == 32)
        cout << "Juiz de Fora\n";
    else if (ddd == 19)
        cout << "Campinas\n";
    else if (ddd == 27)
        cout << "Vitoria\n";
    else if (ddd == 31)
        cout << "Belo Horizonte\n";
    else
        cout << "DDD nao cadastrado\n";

    // system("PAUSE");
    return EXIT_SUCCESS;
}
