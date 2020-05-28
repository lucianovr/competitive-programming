#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    float a, b, c;

    cout << fixed << setprecision(1);
    cin >> a >> b >> c;

    if ((a < b + c) && (b < a + c) && (c < a + b))
        cout << "Perimetro = " << a + b + c << endl;
    else
        cout << "Area = " << ((a + b) * c) / 2 << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}
