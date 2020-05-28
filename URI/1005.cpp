#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << fixed << setprecision(5);
    double a, b, med;

    cin >> a;
    cin >> b;

    med = (3.5 * a + 7.5 * b) / 11;

    cout << "MEDIA = " << med << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
