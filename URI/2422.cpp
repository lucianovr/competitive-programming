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

//              <- ^ -> v
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

/*
    Rep(i,4){
                a = x + dx[i];
                b = y + dy[i];
                if (dentro(a,b,n,m))	{
                        ...
                }
    }
*/

int main() {

    int t, n, m;

    scanf("%d", &n);
    vi v(n);

    Rep(i, n) scanf("%d", &v[i]);
    scanf("%d", &m);

    int i = 0, j = n - 1;

    while (i < j) {
        t = v[i] + v[j];

        if (t == m) {
            printf("%d %d\n", v[i], v[j]);
        }

        if (t > m) {
            j--;
        } else {
            i++;
        }
    }

    return 0;
}
