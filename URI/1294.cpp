#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
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
const double EPS = 1e-10;
int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

int cmp_eq(double x, double y) { return cmp(x, y) == 0; }
int cmp_lt(double x, double y) { return cmp(x, y) < 0; }

int main() {
    double l, w, MAX, MIN1 = 0.000, MIN2;

    cout << fixed << setprecision(3);

    while (cin >> l >> w) {
        double MIN2 = min(l, w) / 2.0, A, B, C;
        A = 12.0;
        B = -4.0 * (l + w), C = l * w;
        double delta = B * B - 4.0 * A * C;
        double raiz = sqrt(delta);
        double x1 = (-B + raiz) / (2.0 * A);
        double x2 = (-B - raiz) / (2.0 * A);
        double v1 = x1 * (l - x1 - x1) * (w - x1 - x1);
        double v2 = x2 * (l - x2 - x2) * (w - x2 - x2);

        if (v1 > v2)
            MAX = x1;
        else
            MAX = x2;

        cout << MAX << " " << MIN1 << " " << MIN2 << endl;
    }

    return 0;
}
