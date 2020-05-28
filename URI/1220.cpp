#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, i;
    double s[1001], med, aux, soma, soma2;

    while (cin >> n && n) {
        med = 0.0;
        soma = 0.0;
        soma2 = 0.0;
        for (i = 0; i < n; i++) {
            cin >> s[i];
            med += s[i];
        }
        med = med / n;

        for (i = 0; i < n; i++) {
            if (s[i] < med) {
                aux = (med - s[i]);
                aux = aux * 100;
                aux = (int)aux;
                soma += (double)(aux / 100);
            } else {
                aux = (s[i] - med);
                aux = aux * 100;
                aux = (int)aux;
                soma2 += (double)(aux / 100);
            }
        }

        cout << fixed << setprecision(2);
        if (soma > soma2)
            cout << "$" << soma << endl;
        else
            cout << "$" << soma2 << endl;

    } // while

    return 0;
}