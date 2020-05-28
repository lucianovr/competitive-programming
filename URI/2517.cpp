#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

double A, B, C;
double xc, yc, xf;

double f(double x) { return ((-x * x) / A) - (x / B) + C; }

double dist(double x) {
    double y = f(x);
    return hypot(xc - x, yc - y);
}

int main() {

    while (scanf("%lf%lf%lf", &A, &B, &C) == 3) {
        scanf("%lf %lf %lf", &xc, &yc, &xf);

        double lo = 0, hi = xf, tam, x1, x2;
        while (fabs(lo - hi) > EPS) {
            tam = fabs(hi - lo) / 3.0;
            x1 = lo + tam;
            x2 = lo + 2 * tam;
            if (dist(x1) < dist(x2)) {
                hi = x2;
            } else
                lo = x1;
        }
        printf("%.2lf\n", dist(lo));
    }
    return 0;
}