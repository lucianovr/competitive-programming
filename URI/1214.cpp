#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    cout << fixed << setprecision(3);
    float c, n, cont;
    float v[1001], s;

    cin >> c;
    for (int j = 0; j < c; j++) {
        s = 0;
        cont = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            s += v[i];
        }
        s /= n;
        for (int i = 0; i < n; i++)
            if (v[i] > s)
                cont++;
        cout << (cont / n) * 100 << "%\n";
    }

    return 0;
}