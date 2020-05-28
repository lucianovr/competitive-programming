#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int v[5], cont = 0;

    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0) {
            cont++;
        }
    }
    cout << cont << " valores pares\n";

    // system("PAUSE");
    return EXIT_SUCCESS;
}
