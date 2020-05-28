#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define STD std::ios::sync_with_stdio(false)

double func(double x, double y, double z) {
    if (x < 0 || y < 0 || z < 0)
        return -1.0;
    double a = sqrt(x), b = sqrt(y), c = sqrt(z);

    if ((a < (b + c)) && (b < (a + c)) && (c < (a + b))) {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    return -1.0;
}

int main() {
    double m1, m2, m3, x, y, z, r, s, t;

    while (scanf("%lf %lf %lf", &m1, &m2, &m3) != EOF) {
        r = 4 * m1 * m1;
        s = 4 * m2 * m2;
        t = 4 * m3 * m3;

        z = (-2.0 * r - 2.0 * s + t) / -9.0;
        y = (2.0 * r + s - 6.0 * z) / 3.0;
        x = -r + 2.0 * z + 2.0 * y;

        printf("%0.3lf\n", func(x, y, z));
    }
    return 0;
}
