#include <iostream>

using namespace std;

int main() {

    int i, n, c, acc, aux, x[55], max;

    while (cin >> n) {
        if (n == 0)
            cout << 0 << endl;
        else {
            cin >> c;
            for (i = 0; i < n; i++) {
                cin >> aux;
                x[i] = aux - c;
            }
            acc = 0;
            max = -50005;

            for (i = 0; i < n; i++) {
                acc += x[i];
                if (acc > max)
                    max = acc;
                if (acc < 0)
                    acc = 0;
            }
            if (max > 0)
                cout << max;
            else
                cout << 0;
            cout << endl;
        }
    }
    // system("PAUSE");
    return 0;
}