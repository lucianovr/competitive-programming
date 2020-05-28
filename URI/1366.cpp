#include <iostream>
using namespace std;

int main() {

    int n, c, v[1000], cont, i;

    while (cin >> n && n) {
        cont = 0;
        for (i = 0; i < n; i++) {
            cin >> c >> v[i];
            if (v[i] > 1)
                cont += (int)v[i] / 2;
        }

        cout << (int)2 * cont / 4 << endl;
    }
    return 0;
}