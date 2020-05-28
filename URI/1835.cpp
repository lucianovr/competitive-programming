// flood fill
// numero de componentes
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

#define MAXN 100 + 10

VI adj[MAXN];
int vis[MAXN];

void dfs(int u) {
    vis[u] = 1;
    rep(i, 0, adj[u].size()) if (!vis[adj[u][i]]) dfs(adj[u][i]);
}

int main() {
    int t, caso(1), n, m, a, b, ncomp;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);

        rep(i, 0, n) adj[i].clear(), vis[i] = 0;

        while (m--) {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        ncomp = 0;
        rep(i, 0, n) if (!vis[i]) {
            ncomp++;
            dfs(i);
        }

        printf("Caso #%d: ", caso++);
        if (ncomp == 1)
            printf("a promessa foi cumprida\n");
        else
            printf("ainda falta(m) %d estrada(s)\n", ncomp - 1);
    }
    return 0;
}
