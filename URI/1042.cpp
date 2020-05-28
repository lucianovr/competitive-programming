#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int a, b, c, inf, meio, sup, ax;

    cin >> a >> b >> c;
    sup = a;
    meio = b;
    inf = c;

    if (inf > meio) {
        ax = meio;
        meio = inf;
        inf = ax;
        if (meio > sup) {
            ax = sup;
            sup = meio;
            meio = ax;
        }
    }

    if (meio > sup) {
        ax = sup;
        sup = meio;
        meio = ax;
    }

    if (inf > meio) {
        ax = meio;
        meio = inf;
        inf = ax;
    }

    cout << inf << endl;
    cout << meio << endl;
    cout << sup << endl << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}