#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

#define MAX 50 * 50 + 10
int pd[MAX][MAX];
char grid[55][55];
int mod = 1e9 + 7;

int C(int n, int k) {
    if (n == k || k == 0)
        return 1;
    if (pd[n][k] != -1)
        return pd[n][k];

    return pd[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % mod;
}

int main() {
    int n, m;
    memset(pd, -1, sizeof pd);
    int N, K;

    while (scanf("%d %d", &n, &m) == 2) {
        rep(i, 0, n) rep(j, 0, m) { scanf(" %c", &grid[i][j]); }
        int x1, y1, x2, y2;
        while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
            x1--;
            y1--;
            x2--;
            y2--;
            N = (x2 - x1 + 1) * (y2 - y1 + 1);
            K = 0;

            for (int i = x1; i <= x2; ++i)
                for (int j = y1; j <= y2; ++j) {
                    if (grid[i][j] == '#')
                        K++;
                }
            printf("%d\n", (C(N, K) - 1 + mod) % mod);
        }
    }
    return 0;
}
