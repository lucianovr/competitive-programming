#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    float s, pr;

    cin >> s;

    if (s <= 400.00) {
        pr = 15;
    }

    else if (s <= 800.00) {
        pr = 12;
    }

    else if (s <= 1200.00) {
        pr = 10;
    }

    else if (s <= 2000.00) {
        pr = 7;
    }

    else {
        pr = 4;
    }

    cout << fixed << setprecision(2);
    cout << "Novo salario: " << s * (1 + pr / 100) << endl;
    cout << "Reajuste ganho: " << s * (pr / 100) << endl;
    cout << fixed << setprecision(0);
    cout << "Em percentual: " << pr << " %\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}