#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int i, x;

    cin >> x;

    for (i = 0; i <= x; i++) {
        if (i % 2 == 1)
            cout << i << endl;
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
