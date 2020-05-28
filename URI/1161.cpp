#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int m, n;
    unsigned long long v[20];

    v[0] = 1ULL;
    for (int i = 1; i <= 20; i++) {
        v[i] = v[i - 1] * i;
    }

    while (cin >> m >> n && (m >= 0 && n >= 0)) {
        cout << v[m] + v[n] << endl;
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}