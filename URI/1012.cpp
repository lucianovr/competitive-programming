#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << fixed << setprecision(3);
    float a, b, c, pi = 3.14159;

    cin >> a >> b >> c;

    cout << "TRIANGULO: " << (a * c) / 2 << endl;

    cout << "CIRCULO: " << pi * c * c << endl;

    cout << "TRAPEZIO: " << ((a + b) * c) / 2 << endl;

    cout << "QUADRADO: " << b * b << endl;

    cout << "RETANGULO: " << a * b << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
