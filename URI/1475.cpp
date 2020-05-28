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

int N, C, T1, T2, maC;
int v[1009], dp[1009];

int solve(int i, int cAtual) {
    if (i >= N || cAtual > maC)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int p1 = upper_bound(v, v + N, v[i] + T1) - v;
    int p2 = upper_bound(v, v + N, v[i] + T2) - v;

    int r1 = T1 + solve(p1, v[i] + T1);
    int r2 = T2 + solve(p2, v[i] + T2);

    return dp[i] = min(r1, r2);
}

int main() {
    while (scanf("%d%d%d%d", &N, &C, &T1, &T2) == 4) {
        rep(i, 0, N) scanf("%d", &v[i]);

        sort(v, v + N);
        maC = v[N - 1];

        for (int i = 0; i <= N; i++)
            dp[i] = -1;

        printf("%d\n", solve(0, 0));
    }
    return 0;
}
