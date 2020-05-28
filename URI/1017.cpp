#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    float t, v;

    cin >> t;
    cin >> v;

    cout << fixed << setprecision(3);
    cout << (v * t) / 12 << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}
