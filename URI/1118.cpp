#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    float n1, n2, x = 1;
    cout << fixed << setprecision(2);
    while (x == 1) {
        do {
            cin >> n1;
            if (!(n1 >= 0 && n1 <= 10))
                cout << "nota invalida\n";
        } while (!(n1 >= 0 && n1 <= 10));

        do {
            cin >> n2;
            if (!(n2 >= 0 && n2 <= 10))
                cout << "nota invalida\n";
        } while (!(n2 >= 0 && n2 <= 10));

        cout << "media = " << (n1 + n2) / 2 << endl;

        do {
            cout << "novo calculo (1-sim 2-nao)\n";
            cin >> x;
        } while (x != 1 && x != 2); // x==1 ||
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
