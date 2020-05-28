#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << fixed << setprecision(5);
    double a, b, c, d, rdelta, r1, r2;
    cin >> a >> b >> c;

    if (a == 0)
        cout << "Impossivel calcular\n";
    else {
        d = b * b - 4 * a * c;
        if (d < 0)
            cout << "Impossivel calcular\n";
        else {
            rdelta = pow(d, 0.5);
            r1 = (-b + rdelta) / (2 * a);
            r2 = (-b - rdelta) / (2 * a);
            cout << "R1 = " << r1 << endl;
            cout << "R2 = " << r2 << endl;
        }
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
