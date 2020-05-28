#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << fixed << setprecision(1);
    double a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    cout << "MEDIA = " << (2 * a + 3 * b + 5 * c) / 10 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
