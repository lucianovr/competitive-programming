#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define Rep(i, b) rep(i, 0, b)
#define tr(it, v) for (typeof(v.begin()) it = v.begin(); it != v.end(); ++it)
#define all(v) (v.begin(), v.end())
#define pb push_back
#define contains(S, x) (S.find(x) != S.end())
#define dentro(a, b, n, m) (a >= 0 && a < n && b >= 0 && b < m)
/* printa matriz A[n][m]*/
#define printM(A, n, m)                                                                                                \
    Rep(i, n) {                                                                                                        \
        Rep(j, m) {                                                                                                    \
            cout << A[i][j];                                                                                           \
            if (j != m - 1)                                                                                            \
                cout << "#";                                                                                           \
        }                                                                                                              \
        cout << "\n";                                                                                                  \
    }

const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

int main() {

    int a, b, c;
    int x, y, z;

    cin >> a >> b >> c >> x >> y >> z;

    int C, F;
    C = a * 3 + b;
    F = x * 3 + y;

    if (C > F)
        cout << "C\n";
    else if (C < F)
        cout << "F\n";
    else {
        if (c == z)
            cout << "=\n";
        else
            cout << (c > z ? "C\n" : "F\n");
    }

    return 0;
}
