#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    unsigned long long int v[61];

    int t, n;

    v[0] = 0ULL;
    v[1] = 1ULL;
    v[2] = 1ULL;
    v[3] = 2ULL;

    for (int i = 2; i < 61; i++)
        v[i] = v[i - 1] + v[i - 2];

    cin >> t;
    for (int j = 0; j < t; j++) {
        cin >> n;
        cout << "Fib(" << n << ") = " << v[n] << endl;
    }

    // system ("PAUSE");
    return 0;
}
