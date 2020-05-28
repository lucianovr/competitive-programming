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

const int MAXV = 500010;
const int LOGMAXN = 16;
int N;
vector<int> adj[MAXV];
int T[MAXV], P[MAXV][LOGMAXN], L[MAXV];
bool vis[MAXV];

int lca(int p, int q) {
    int log, i;
    if (L[p] < L[q])
        swap(p, q);

    for (log = 1; 1 << log <= L[p]; log++) {
    }
    log--;

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return T[p];
}

void process() {
    int i, j;
    rep(i, 0, N) for (int j = 0; 1 << j < N; j++) P[i][j] = -1;

    rep(i, 0, N) P[i][0] = T[i];

    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

void dfs(int u, int n) {
    vis[u] = true;
    L[u] = n;
    rep(i, 0, adj[u].size()) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v, n + 1);
            T[v] = u;
        }
    }
}

int main() {

    cin >> N;
    vector<int> v[N];
    int x;
    rep(i, 0, N) {
        cin >> x;
        v[x].pb(i);

        adj[i].clear();
        vis[i] = false;
        L[i] = -1;
    }
    int a, b;
    rep(i, 0, N - 1) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, 0);
    process();

    int ans = 0;
    for (int i = 1; i <= N / 2; i++) {
        int u = v[i][0];
        int z = v[i][1];
        int w = lca(u, z);

        ans += abs(L[w] - L[u]) + abs(L[w] - L[z]);
    }

    cout << ans << "\n";

    return 0;
}
