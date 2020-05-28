#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debgu(x) cout << #x << " = " << x;
#define nl cout << "\n";

int main() {

    double L;
    while (cin >> L) {
        double A = (L * L * sqrt(3) / 2) / 2;
        A = 8 * A / 5;

        printf("%.2lf\n", A);
    }

    return 0;
}
