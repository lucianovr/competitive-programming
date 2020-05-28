#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n;
    float comida;

    cin >> n;
    for (int i = 0; i < n; i++) {

        int cont = 0;

        cin >> comida;

        while (comida > 1) {
            comida /= 2;
            cont++;
        }
        cout << cont << " dias\n";
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}