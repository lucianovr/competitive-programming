#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int cimp = 0, x;

    cin >> x;

    while (cimp != 6) {
        if (x % 2 == 1) {
            cout << x << endl;
            cimp++;
        }
        x++;
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
