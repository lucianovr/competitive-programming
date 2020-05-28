#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int n, f1, f2, maior, menor, resto = 1, mdc;

    cin >> n;

    for (int i = n; i > 0; i--) {
        resto = 1;
        cin >> f1 >> f2;
        if (f1 > f2) {
            maior = f1;
            menor = f2;
        } else {
            maior = f2;
            menor = f1;
        }
        while (!(resto == 0)) {
            resto = maior - menor;
            if (resto == 0)
                mdc = menor;
            else if (resto > menor)
                maior = resto;
            else {
                maior = menor;
                menor = resto;
            }
        }
        cout << mdc << endl;
    }
}
