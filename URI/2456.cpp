#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define clear(v) memset(v, 0, sizeof v)
#define initpd(v) memset(v, -1, sizeof v)
#define pb push_back

inline int cmp(double x, double y = 0, double tol = 1e-9) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }
int v[5];

bool crescente() {
    rep(i, 1, 5) {
        if (v[i] < v[i - 1])
            return false;
    }
    return true;
}

bool decrescente() {
    rep(i, 1, 5) {
        if (v[i] > v[i - 1])
            return false;
    }
    return true;
}

char func() {
    if (crescente())
        return 'C';

    if (decrescente())
        return 'D';

    return 'N';
}

int main() {

    for (int i = 0; i < 5; i++)
        cin >> v[i];

    cout << func() << "\n";

    return 0;
}
