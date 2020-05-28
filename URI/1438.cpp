#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int N, P, p, C[1000], i, x, y, caixa, soma1, soma2;

    while (cin >> N >> P && N + P) {
        soma1 = soma2 = 0;
        for (p = 0; p < P; p++) {
            cin >> C[p];
            for (i = 0; i < C[p]; i++) {
                cin >> caixa;
                if (caixa == 1) {
                    x = i;
                    y = p;
                }
            }
        }

        for (i = 0; i <= y; i++) {
            if (C[i] - x > 0)
                soma1 = soma1 + C[i] - x;
            else
                soma1 = 0;
        }
        for (i = y; i < P; i++) {
            if (C[i] - x > 0)
                soma2 = soma2 + C[i] - x;
            else
                break;
        }
        if (soma1 < soma2) {
            if (soma1 == 0)
                cout << "0";
            else
                cout << soma1 - 1;
        } else {
            if (soma2 == 0)
                cout << "0";
            else
                cout << soma2 - 1;
        }
        cout << endl;
    }
    return 0;
}
