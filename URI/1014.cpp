#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {

    cout << fixed << setprecision(3);
    int a;
    float b;

    cin >> a;
    cin >> b;

    cout << a / b << " km/l\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}
