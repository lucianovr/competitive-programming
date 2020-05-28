#include <iostream>
using namespace std;

int main() {

    int T, n, v[60];
    int i, t, c, aux;
    bool B;
    cin >> T;
    for (t = 0; t < T; t++) {
        B = true;
        c = 0;
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> v[i];
        while (B) {
            B = false;
            for (i = 1; i < n; i++)
                if (v[i - 1] > v[i]) {
                    aux = v[i];
                    v[i] = v[i - 1];
                    v[i - 1] = aux;
                    c++; // conta qtas trocas foram feitas
                    B = true;
                }
        }
        cout << "Optimal train swapping takes " << c << " swaps.\n";
    }
    return 0;
}
