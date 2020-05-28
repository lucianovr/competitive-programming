#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debgu(x) cout << #x << " = " << x;
#define nl cout << "\n";

const double PI = acos(-1);

inline double toRad(double x) { return x * PI / 180.0; }
int main() {
    double A, D, H;
    while (scanf("%lf %lf %lf", &A, &D, &H) == 3) {
        double h = 5 * (H + D * tan(toRad(A)));

        printf("%.2lf\n", h);
    }
    return 0;
}
