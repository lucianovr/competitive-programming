#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

#define MAX 15 * 15
const int mod = 1300031;

int n;
LL ans[MAX][MAX], adj[MAX][MAX], c[MAX][MAX];
LL gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void multiply(LL a[][MAX], LL b[][MAX]) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < n * n; i++)
        for (int j = 0; j < n * n; j++) {
            for (int k = 0; k < n * n; k++)
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]));
            c[i][j] %= mod;
        }

    memcpy(a, c, sizeof(c));
}

int main() {
    int p;
    while (scanf("%d %d", &n, &p) && n + p) {
        memset(adj, 0, sizeof adj);
        memset(ans, 0, sizeof ans);

        rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) rep(l, 0, n) adj[i * n + j][k * n + l] =
            (gcd(abs(k - i), abs(l - j)) == 1);

        rep(i, 0, n * n) ans[i][i] = 1;
        p--;
        while (p) {
            if (p & 1)
                multiply(ans, adj);
            p = p >> 1;
            multiply(adj, adj);
        }

        LL sum = 0;
        rep(i, 0, n * n) rep(j, 0, n * n) sum = (sum % mod + ans[i][j] % mod) % mod;

        cout << sum << "\n";
    }
    return 0;
}
