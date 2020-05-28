#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int a, d, at, pd, sd, D, aux;

    while (cin >> a >> d && a + d) {

        at = pd = sd = 10099;
        for (int i = 0; i < a; i++) {
            cin >> aux;
            if (aux < at)
                at = aux;
        }
        for (int i = 0; i < d; i++) {
            cin >> D;
            if (D < sd)
                sd = D;
            if (sd < pd) {
                aux = pd;
                pd = sd;
                sd = aux;
            }
        }
        if (at >= sd && at >= pd)
            cout << "N\n";
        else
            cout << "Y\n";
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
