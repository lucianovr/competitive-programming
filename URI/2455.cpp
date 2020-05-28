#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define clear(v) memset(v, 0, sizeof v)
#define initpd(v) memset(v, -1, sizeof v)
#define pb push_back

inline int cmp(double x, double y = 0, double tol = 1e-9) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

int main() {
    int c1, p2, p1, c2;
    int r1, r2;

    cin >> p1 >> c1 >> p2 >> c2;

    r1 = p1 * c1;
    r2 = p2 * c2;
    if (r1 == r2)
        cout << 0 << "\n";
    else if (r1 < r2)
        cout << 1 << "\n";
    else
        cout << -1 << "\n";
    return 0;
}
