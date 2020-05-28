#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int t, cont = 0, a, b;
    double x, y;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> x >> y;
        cont = 0;
        while (a <= b && cont <= 100) {
            a = a + a * (x / 100);
            b = b + b * (y / 100);
            cont++;
        }
        if (cont > 100)
            cout << "Mais de 1 seculo.\n";
        else
            cout << cont << " anos.\n";
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
