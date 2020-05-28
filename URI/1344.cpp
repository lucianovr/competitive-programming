#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mk make_pair
#define debug(x) cout << #x << " = " << x << "\n";
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int g[1010][1010], n;
int deg[1010];
int A;

struct comp {
    inline bool operator()(const int u, const int v) { return (deg[u] != deg[v]) ? deg[u] < deg[v] : u < v; }
};
set<int, comp> s;

void doit(int v) {
    deg[v] = 0;
    rep(u, 1, n + 1) {
        if (g[v][u] > 0) {
            g[v][u] = g[u][v] = 0;
            s.erase(u);
            --deg[u];
            s.insert(u);
        }
    }
}

int vis[1010];
int sol() {
    s.clear();
    rep(i, 1, n + 1) s.insert(i);

    while (!s.empty()) {
        int v = *(s.begin());
        // cout << v << " " << deg[v] << "\n";
        if (deg[v] >= A)
            return s.size();
        s.erase(v);
        doit(v);
    }
    return s.size();
}

int cont;
void dfs(int v) {
    if (vis[v] == 1 || deg[v] < A)
        return;
    vis[v] = 1;
    cont++;
    for (int u = 1; u <= n; u++) {
        if (g[v][u] > 0)
            dfs(u);
    }
}

int main() {
    int m;
    while (scanf("%d %d %d", &n, &m, &A) && n) {
        memset(g, 0, sizeof g);
        memset(deg, 0, sizeof deg);
        int u, v;
        rep(i, 0, m) {
            scanf("%d %d", &u, &v);
            g[u][v] = g[v][u] = 1;
            deg[u]++;
            deg[v]++;
        }
        int ma = 0;
        sol();

        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && deg[i] >= A) {
                cont = 0;
                dfs(i);
                ma = max(ma, cont);
            }
        }
        printf("%d\n", ma);
    }
    return 0;
}
