#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

int N;
int E[16][16];
ll pd[16][1 << 16][6];

ll tsp(int v, int mask, int k) {
    if (mask == (1 << N) - 1)
        return pd[v][mask][k] = 0;
    ll r = pd[v][mask][k];
    if (r != -1)
        return r;

    r = INF;
    for (int u = 0; u < N; u++) {
        if (u == v || mask & (1 << u))
            continue;

        if (k)
            r = min(r, tsp(u, mask | (1 << u), k - 1));
        if (E[v][u] != INF)
            r = min(r, tsp(u, mask | (1 << u), k) + E[v][u]);
    }
    return pd[v][mask][k] = r;
}

int main() {
    int t;
    int M, K;
    int u, v, c;

    cin >> t;
    while (t--) {
        cin >> N >> M >> K;
        memset(E, INF, sizeof E);
        rep(i, 0, N) E[i][i] = 0;
        while (M--) {
            cin >> u >> v >> c;
            u--, v--;
            E[u][v] = E[v][u] = min(E[u][v], c);
        }
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    E[i][j] = min(E[i][j], E[i][k] + E[k][j]);

        memset(pd, -1, sizeof pd);
        long long ret = tsp(0, 1, K);
        if (ret == INF)
            ret = -1;

        cout << ret << "\n";
    }
    return 0;
}
