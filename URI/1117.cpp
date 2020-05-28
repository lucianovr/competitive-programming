#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    float a, soma = 0;
    int i = 0;

    while (i != 2) {
        cin >> a;
        if (a >= 0 && a <= 10) {
            soma += a;
            i++;
        } else
            cout << "nota invalida\n";
    }
    cout << fixed << setprecision(2);
    cout << "media = " << soma / 2 << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}