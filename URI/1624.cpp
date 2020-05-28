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

int preco[110], peso[110], n;
int pd[110][3010];

int solve(int i, int p) {
    if (i == n)
        return 0;
    if (pd[i][p] != -1)
        return pd[i][p];

    int res = solve(i + 1, p);
    if (peso[i] <= p)
        res = max(res, solve(i + 1, p - peso[i]) + preco[i]);

    return pd[i][p] = res;
}

int main() {
    int M;
    while (scanf("%d", &n) && n) {
        rep(i, 0, n) { scanf("%d %d", &preco[i], &peso[i]); }
        scanf("%d", &M);
        rep(i, 0, n) rep(j, 0, M + 1) pd[i][j] = -1;

        printf("%d\n", solve(0, M));
    }
    return 0;
}
