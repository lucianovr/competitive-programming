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
    int N, M;
    int a, b, u, v;

    cin >> N >> M;
    cin >> a >> b >> u >> v;

    if (a + u <= N && max(b, v) <= M)
        cout << "S\n";
    else if (b + u <= N && max(a, v) <= M)
        cout << "S\n";
    else if (a + v <= N && max(b, u) <= M)
        cout << "S\n";
    else if (b + v <= N && max(a, u) <= M)
        cout << "S\n";
    else {
        swap(N, M);
        if (a + u <= N && max(b, v) <= M)
            cout << "S\n";
        else if (b + u <= N && max(a, v) <= M)
            cout << "S\n";
        else if (a + v <= N && max(b, u) <= M)
            cout << "S\n";
        else if (b + v <= N && max(a, u) <= M)
            cout << "S\n";
        else
            cout << "N\n";
    }

    return 0;
}
