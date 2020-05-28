#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define contem(s, x) (s.find(x) != s.end())

const double pi = acos(-1), EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

int cmp_eq(double x, double y) { return cmp(x, y) == 0; }

int cmp_lt(double x, double y) { return cmp(x, y) < 0; }

double bs(double ini, double fim, double V, double b, double h) {
    double hi = (ini + fim) / 2;
    double ri = b * hi / h;
    double Vi = pi * ri * ri * hi / 3.0;

    if (cmp_eq(ini, fim) || cmp_eq(Vi, V))
        return hi;

    else if (cmp_lt(Vi, V))
        return bs(hi, fim, V, b, h);

    else
        return bs(ini, hi, V, b, h);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        double b, B, l, n, H, hi;
        cin >> n >> l >> b >> B >> H;

        if (cmp_eq(b, B))
            hi = (l / n) / (pi * b * b);
        else {
            double h = (H * b) / (B - b);
            double V = l / n + (pi * b * b * h) / 3.0;
            hi = bs(h, h + H, V, b, h);
            hi = hi - h;
        }

        cout << fixed << setprecision(2) << hi << endl;
    }
    return 0;
}
