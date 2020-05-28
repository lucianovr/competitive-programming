#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

inline bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
inline bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};

int main() {
    int t, n, v[10001], ans, i, j;

    scanf("%d", &t);
    while (t--) {

        scanf("%d", &n);
        rep(k, 0, n) scanf("%d", &v[k]);
        sort(v, v + n);

        i = 0;
        ans = 1;
        for (j = 1; j < n; j++)
            if (v[j] != v[i]) {
                ans++;
                i = j;
            }
        printf("%d\n", ans);
    }
    return 0;
}
