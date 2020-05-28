#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int func(int a, int b, int n) {
    int A, B, c, d;

    if (b == 0)
        return 1;
    if (a == 0)
        return 2;
    c = a;
    d = b;
    for (int i = 1; i <= n; i++) {
        if (b == 0)
            return i;
        A = a * c - b * d;
        B = a * d + b * c;
        a = A;
        b = B;
    }
    return -1;
}

int main() {
    double A, B, p;
    int m, n;
    cin >> m;
    while (m--) {
        cin >> A >> B;
        p = sqrt(A * A + B * B);
        n = (log(2) * 30) / log(p);
        int ret = func((int)A, (int)B, n);
        if (ret == -1)
            cout << "TOO COMPLICATED\n";
        else
            cout << ret << endl;
    }
    return 0;
}
