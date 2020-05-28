#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;

    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            break;
        cout << (a / __gcd(a, b) * b) % 1713371337 << "\n";
    }

    return 0;
}