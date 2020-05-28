#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int p[6], i[6], cp = 0, ci = 0, x;

    for (int j = 0; j < 15; j++) {
        cin >> x;
        if (x % 2 == 0) {
            p[cp] = x;
            cp++;

        } else {
            i[ci] = x;
            ci++;
        }
        if (cp == 5) {
            cp = 0;
            for (int a = 0; a < 5; a++)
                cout << "par[" << a << "] = " << p[a] << endl;
        }
        if (ci == 5) {
            ci = 0;
            for (int a = 0; a < 5; a++)
                cout << "impar[" << a << "] = " << i[a] << endl;
        }
    }

    for (int a = 0; a < ci; a++)
        cout << "impar[" << a << "] = " << i[a] << endl;
    for (int a = 0; a < cp; a++)
        cout << "par[" << a << "] = " << p[a] << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}