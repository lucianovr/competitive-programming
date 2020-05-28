#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)

struct point {
    double x, y, d;
    int k;
    point(double x = 0, double y = 0, double d = 0, int k = 0) : x(x), y(y), d(d), k(k) {}
};

point v[55];

double abs(double x, double y, double x1, double y1) { return hypot(x - x1, y - y1); }
double eps = 0.01;

bool comp(point a, point b) {
    double val = fabs(a.d - b.d);
    if (val > eps)
        return a.d < b.d;
    else
        return a.k < b.k;
}

int main() {
    int t, n, numb;
    double x, y;
    point w;

    scanf("%d", &t);
    rep(i, 0, t) {
        scanf("%d", &n);

        scanf("%lf %lf", &x, &y);
        w = point(x, y, 0, 0);

        for (int j = 1; j <= n; j++) {
            scanf("%lf %lf", &x, &y);
            v[j] = point(x, y, abs(x, y, w.x, w.y), j);
        }

        sort(v + 1, v + n + 1, comp);
        printf("%d\n", v[1].k);
    }
    return 0;
}